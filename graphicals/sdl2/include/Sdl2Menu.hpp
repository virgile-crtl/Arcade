/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Sdl2Menu
*/

#ifndef SDL2MENU_HPP_
#define SDL2MENU_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "Core.hpp"

class Sdl2Menu {
    public:
        Sdl2Menu(std::vector<std::string>& _libsGame,
            std::vector<std::string>& _libsGraph, int gameSlc, int graphSlc);
        ~Sdl2Menu();

        void init(SDL_Renderer* _renderer);
        void initGames(SDL_Renderer* _renderer);
        void initGraphs(SDL_Renderer* _renderer);
        void resized();
        void moveCursor(int gameSlc, int graphSlc, SDL_Renderer* _renderer);
        void display(SDL_Renderer* _renderer) const;

        int slcGame;
        int slcGraph;
        std::pair<SDL_Texture *, SDL_Rect> background;
    protected:
    private:
        std::string _fontPath;
        std::vector<SDL_Color> _colors;
        std::vector<std::pair<SDL_Texture *, SDL_Rect>> _spriteGraphs;
        std::vector<std::pair<SDL_Texture *, SDL_Rect>> _spriteGames;
        std::vector<std::string>& _libGames;
        std::vector<std::string>& _libGraphs;
};

SDL_Texture* CreateText(std::string font, std::string text,
    int police, SDL_Renderer *renderer, SDL_Color color);
int getScale(double basicSize, double windowDrawSize, double windowSize);
void setName(std::string& libname);

#endif /* !SDL2MENU_HPP_ */
