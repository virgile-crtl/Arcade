/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Sdl2
*/

#include "Sdl2.hpp"

Sdl2::Sdl2(Menu& coreMenu) : _sdl2Menu(coreMenu.libsGame,
coreMenu.libsGraph, coreMenu.slcGame, coreMenu.slcGraph),  _kEvent(initEvent())
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    _renderer = SDL_CreateRenderer(_window, -1,
    SDL_RENDERER_ACCELERATED);
    _sdl2Menu.init(_renderer);
    initTexture();
    SDL_Event event;
    SDL_PollEvent(&event);
}

Sdl2::~Sdl2()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    TTF_Quit();
    SDL_Quit();
}

void Sdl2::refresh()
{
    SDL_RenderClear(_renderer);
}

void Sdl2::displayGame(std::vector<std::string> game, int score)
{
    int x, y;
    int size;
    SDL_Rect rec;

    refresh();
    SDL_GetWindowSize(_window, &x, &y);
    size = ((x - 200) / game[0].size());
    if (size > y / (int)game.size())
        size = y / game.size();
    x = ((x / 2) - ((game[0].size() / 2) * size));
    rec = {x, (int)((y / 2) - (game.size() / 2) * size), size, size};
    for (int i = 0; i < (int)game.size(); i+=1, rec.x = x, rec.y += size)
        for (int j = 0; j < (int)game[i].size(); j+=1, rec.x += size)
            if (_texture[game[i][j]])
                SDL_RenderCopy(_renderer, _texture[game[i][j]], nullptr, &rec);
    rec = {0, 0, 100, 100};
    SDL_RenderCopy(_renderer, CreateText
    ("assets/sdl_text_font.ttf", std::to_string(score), 100,
    _renderer, {.r = 255, .g = 255, .b = 255, .a = 0}), nullptr, &rec);
    SDL_RenderPresent(_renderer);
}


void Sdl2::displayMenu(int gameSlc, int graphSlc)
{
    SDL_Rect tmp;
    SDL_GetWindowSize(_window, &tmp.w, &tmp.h);

    if (tmp.h != _sdl2Menu.background.second.h
    || tmp.w != _sdl2Menu.background.second.w) {
        _sdl2Menu.background.second.w = tmp.w;
        _sdl2Menu.background.second.h = tmp.h;
        _sdl2Menu.resized();
    }
    _sdl2Menu.moveCursor(gameSlc, graphSlc, _renderer);
    _sdl2Menu.display(_renderer);
}


void Sdl2::displayScore()
{
}

keyType Sdl2::keyEvent()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            return quit;
        case SDL_KEYDOWN:
            if (_kEvent[event.key.keysym.sym])
                return _kEvent[event.key.keysym.sym];
    }
    return nokey;
}

void Sdl2::initTexture()
{
    _texture['X'] = IMG_LoadTexture(_renderer, "assets/wall2.png");
    _texture['t'] = IMG_LoadTexture(_renderer, "assets/head.png");
    _texture['n'] = IMG_LoadTexture(_renderer, "assets/body.png");
    _texture['d'] = IMG_LoadTexture(_renderer, "assets/body.png");
    _texture['A'] = IMG_LoadTexture(_renderer, "assets/cherry.png");
    _texture['E'] = IMG_LoadTexture(_renderer, "assets/ghost.png");
    _texture['P'] = IMG_LoadTexture(_renderer, "assets/pacman.png");
    _texture['.'] = IMG_LoadTexture(_renderer, "assets/point.png");
    _texture['o'] = IMG_LoadTexture(_renderer, "assets/bigPoint.png");
    _texture['S'] = IMG_LoadTexture(_renderer, "assets/door.png");
}

void Sdl2::destroy()
{
}
