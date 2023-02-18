/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Sdl2Menu
*/

#include "Sdl2Menu.hpp"

Sdl2Menu::Sdl2Menu(std::vector<std::string>& libsGame, std::vector<std::string>& libsGraph, int gameSlc, int graphSlc)
:  slcGame(gameSlc), slcGraph(graphSlc), _fontPath("assets/sdl_text_font.ttf"), _libGames(libsGame), _libGraphs(libsGraph)
{
}

Sdl2Menu::~Sdl2Menu()
{
    for (int i = 0; i < (int)_spriteGraphs.size(); i += 1)
        SDL_DestroyTexture(_spriteGraphs[i].first);
    for (int i = 0; i < (int)_spriteGames.size(); i += 1)
        SDL_DestroyTexture(_spriteGames[i].first);
}

void Sdl2Menu::display(SDL_Renderer* _renderer) const
{
    SDL_RenderClear(_renderer);

    SDL_RenderCopy(_renderer,
        background.first, nullptr, &background.second);
    for (int i = 0; i < (int)_spriteGraphs.size(); i+=1)
        SDL_RenderCopy(_renderer,
        _spriteGraphs[i].first, nullptr, &_spriteGraphs[i].second);
    for (int i = 0;  i < (int)_spriteGames.size(); i+=1)
        SDL_RenderCopy(_renderer,
        _spriteGames[i].first, nullptr, &_spriteGames[i].second);
    SDL_RenderPresent(_renderer);
}

void Sdl2Menu::init(SDL_Renderer* _renderer)
{
    _colors.push_back({.r = 255, .g = 0, .b = 0, .a = 0});
    _colors.push_back({.r = 255, .g = 255, .b = 255, .a = 0});

    background = std::make_pair(
        IMG_LoadTexture(_renderer, "assets/background_sdl_menu.jpg"),
        (SDL_Rect){0, 0, 1920, 1080});

    initGraphs(_renderer);
    initGames(_renderer);
}

void Sdl2Menu::initGraphs(SDL_Renderer* _renderer)
{
    int size = 60;
    int i = 0;

    for (std::string tmp : _libGraphs) {
        setName(tmp);
        if(i == slcGraph)
            _spriteGraphs.push_back(std::make_pair(
                CreateText(_fontPath, tmp + " /", 50, _renderer, _colors[0]),
                    (SDL_Rect){(background.second.w / 4) + size,
                    (background.second.h / 2) - 130, 150, 40}));
        else
            _spriteGraphs.push_back(std::make_pair(
                CreateText(_fontPath, tmp + " /", 50, _renderer, _colors[1]),
                    (SDL_Rect){(background.second.w / 4) + size,
                    (background.second.h / 2) - 130, 150, 40}));
        size += 165;
        i += 1;
    }
}

void Sdl2Menu::initGames(SDL_Renderer* _renderer)
{
    int size = 70;

    for (std::string tmp : _libGames) {
        setName(tmp);
        if (size / 70 - 1 == slcGame)
            _spriteGames.push_back(std::make_pair(
                CreateText(_fontPath, tmp, 100, _renderer, _colors[0]),
                    (SDL_Rect){(background.second.w / 2) - 100,
                    (background.second.h / 2) + size, 200, 40}));
        else
            _spriteGames.push_back(std::make_pair(
                CreateText(_fontPath, tmp, 100, _renderer, _colors[1]),
                    (SDL_Rect){(background.second.w / 2) - 100,
                    (background.second.h / 2) + size, 200, 40}));
        size += 70;
    }
}

void Sdl2Menu::resized()
{
    int bSize = 540;
    for (int i = 0; i < (int)_spriteGraphs.size(); i += 1) {
        _spriteGraphs[i].second = {getScale(bSize, 1920, background.second.w),
            getScale(410, 1080, background.second.h), getScale(150,
            1920, background.second.w), getScale(40,
            1080, background.second.h)};
        bSize += 165;
    }
    bSize = 610;
    for (int i = 0; i < (int)_spriteGames.size(); i += 1) {
        _spriteGames[i].second = {getScale(860, 1920, background.second.w),
            getScale(bSize, 1080, background.second.h), getScale(200, 1920,
            background.second.w), getScale(40, 1080, background.second.h)};
        bSize += 70;
    }
}

void Sdl2Menu::moveCursor(int gameSlc, int graphSlc, SDL_Renderer* _renderer)
{
    if (gameSlc != slcGame) {
        std::string tmp = _libGames[slcGame];
        setName(tmp);
        _spriteGames[slcGame].first = CreateText
        (_fontPath, tmp, 16, _renderer, _colors[1]);
        slcGame = gameSlc;
        tmp = _libGames[slcGame];
        setName(tmp);
        _spriteGames[slcGame].first = CreateText
        (_fontPath, tmp, 16, _renderer, _colors[0]);
    }
    if (graphSlc != slcGraph) {
        std::string tmp = _libGraphs[slcGraph];
        setName(tmp);
        _spriteGraphs[slcGraph].first = CreateText
        (_fontPath, tmp, 16, _renderer, _colors[1]);
        slcGraph = graphSlc;
        tmp = _libGraphs[slcGraph];
        setName(tmp);
        _spriteGraphs[slcGraph].first = CreateText
        (_fontPath, tmp, 16, _renderer, _colors[0]);
    }
}