/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** utils
*/

#include "Sdl2.hpp"

SDL_Texture* CreateText(std::string font, std::string text,
int police, SDL_Renderer *renderer, SDL_Color color)
{
    TTF_Font *text_font = TTF_OpenFont(font.c_str(), police);
    SDL_Surface *text_surface = TTF_RenderText_Blended(text_font, text.c_str(), color);
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_FreeSurface(text_surface);
    TTF_CloseFont(text_font);
    return text_texture;
}

int getScale(double basicSize, double windowDrawSize, double windowSize)
{
    double scale = basicSize / windowDrawSize;
    int res = scale * windowSize;
    return (res);
}

void setName(std::string& libname)
{
    libname = strrchr(libname.c_str(), '/');
    libname.erase(libname.begin());
    reverse(libname.begin(), libname.end());
    libname = strchr(libname.c_str(), '.');
    libname.erase(libname.begin());
    reverse(libname.begin(), libname.end());
}

std::map<SDL_Keycode, keyType> initEvent()
{
    std::map<SDL_Keycode, keyType> evnt = {
        {SDLK_UP, up},
        {SDLK_DOWN, down},
        {SDLK_LEFT, left},
        {SDLK_RIGHT, right},
        {SDLK_ESCAPE, quit},
        {SDLK_RETURN, slc},
        {SDLK_TAB, tab},
        {SDLK_x, x},
        {SDLK_w, w},
        {SDLK_a, a},
        {SDLK_r, restart},
        {SDLK_q, stop}
    };
    return evnt;
}