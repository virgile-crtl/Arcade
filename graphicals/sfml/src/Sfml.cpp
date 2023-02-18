/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Sfml
*/

#include "Sfml.hpp"

Sfml::Sfml(Menu& coreMenu) : _sfmlMenu(coreMenu.libsGame, coreMenu.libsGraph, coreMenu.slcGame, coreMenu.slcGraph), _kEvent(initEvent())
{
    _window.create(sf::VideoMode(1920, 1080), "Arcade", sf::Style::Default);
    _sfmlMenu.init();
    initTexture();
}

Sfml::~Sfml()
{
    _window.close();
}

void Sfml::refresh()
{
    _window.clear(sf::Color::Black);
}

void Sfml::displayGame(std::vector<std::string> game, int score)
{
    int size = 46;
    int x = (1920/2)-(game[0].size()/2)*size;
    int y = ((1080/2)-(game.size()/2)*size)-46;
    refresh();

    sf::Text scor = CreateText(_sfmlMenu.font, std::to_string(score),
        80, sf::Color::White, sf::Text::Bold | sf::Text::Underlined);
    scor.setPosition(5, 1);
    _window.draw(scor);
    for (int i = 0; i < (int)game.size(); i+=1, y += 46, x = (1920/2)-(game[0].size()/2)*size)
        for (int j = 0; j < (int)game[i].size(); j+=1, x+= 46)
            if (game[i][j] != ' ') {
                _texture[game[i][j]].first.setPosition({(float)x, (float)y});
                _window.draw(_texture[game[i][j]].first);
            }
    _window.display();
}


void Sfml::displayMenu(int gameSlc, int graphSlc)
{
    _sfmlMenu.moveCursor(gameSlc, graphSlc);
    _sfmlMenu.display(_window);
}


void Sfml::displayScore()
{
}

keyType Sfml::keyEvent()
{
    sf::Event event;

    if (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return quit;
        if (event.type == event.KeyPressed)
            if (_kEvent[event.key.code]) {
                return _kEvent[event.key.code];
            }
    }
    return nokey;
}

void Sfml::destroy()
{
}

void Sfml::initTexture()
{
    _texture['X'].second.loadFromFile("assets/wall.png", sf::IntRect(0, 0, 46, 46));
    _texture['n'].second.loadFromFile("assets/body.png", sf::IntRect(0, 0, 46, 46));
    _texture['d'].second.loadFromFile("assets/body.png", sf::IntRect(0, 0, 46, 46));
    _texture['A'].second.loadFromFile("assets/apple.png", sf::IntRect(0, 0, 46, 46));
    _texture['t'].second.loadFromFile("assets/head.png", sf::IntRect(0, 0, 46, 46));
    _texture['E'].second.loadFromFile("assets/ghost.png", sf::IntRect(0, 0, 46, 46));
    _texture['P'].second.loadFromFile("assets/pacman.png", sf::IntRect(0, 0, 46, 46));
    _texture['.'].second.loadFromFile("assets/point.png", sf::IntRect(0, 0, 46, 46));
    _texture['o'].second.loadFromFile("assets/bigPoint.png", sf::IntRect(0, 0, 46, 46));
    _texture['S'].second.loadFromFile("assets/door.png", sf::IntRect(0, 0, 46, 46));
    _texture['X'].first.setTexture(_texture['X'].second);
    _texture['n'].first.setTexture(_texture['n'].second);
    _texture['d'].first.setTexture(_texture['d'].second);
    _texture['A'].first.setTexture(_texture['A'].second);
    _texture['t'].first.setTexture(_texture['t'].second);
    _texture['E'].first.setTexture(_texture['E'].second);
    _texture['P'].first.setTexture(_texture['P'].second);
    _texture['.'].first.setTexture(_texture['.'].second);
    _texture['o'].first.setTexture(_texture['o'].second);
    _texture['S'].first.setTexture(_texture['S'].second);
}