/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SfmlMenu
*/

#include "SfmlMenu.hpp"

SfmlMenu::SfmlMenu(std::vector<std::string>& _libsGame, std::vector<std::string>& _libsGraph, int gameSlc, int graphSlc)
: libGames(_libsGame), libGraphs(_libsGraph), slcGame(gameSlc), slcGraph(graphSlc)
{
}

SfmlMenu::~SfmlMenu()
{
}

void SfmlMenu::init()
{
    font.loadFromFile("assets/sdl_text_font.ttf");
    background.second.loadFromFile("assets/background_sfml_menu.jpg",
        sf::IntRect(0, 0, 1920, 1080));
    background.first.setTexture(background.second);

    title = CreateText(font, "Arcade", 200, sf::Color::Red,
        sf::Text::Bold | sf::Text::Underlined);
    title.setPosition(1920 / 2 - 350, 100);

    initGraphs();
    initGames();
}

void SfmlMenu::initGames()
{
    int space = 400;
    int i = 0;

    for (std::string tmp : libGames) {
        setName(tmp);
        if (i == slcGame)
            TGames[i] = CreateText(font, tmp, 30, sf::Color::Red,
                sf::Text::Bold | sf::Text::Underlined);
        else
            TGames[i] = CreateText(font, tmp, 30, sf::Color::White,
                sf::Text::Bold | sf::Text::Underlined);
        TGames[i].setPosition(960 - ((tmp.size() * 16) / 2), space);
        space += 100;
        i += 1;
    }
}

void SfmlMenu::initGraphs()
{
    int space = 0;
    int i = 0;

    for (std::string tmp : libGraphs) {
        setName(tmp);
        if (i == slcGraph)
            TLibs[i] = CreateText(font, tmp + " /", 24,
                sf::Color::Red, sf::Text::Bold);
        else
            TLibs[i] = CreateText(font, tmp + " /", 24,
                sf::Color::White, sf::Text::Bold);
        TLibs[i].setPosition(space,0);
        space += (tmp.size() * 16);
        i += 1;
    }
}

void SfmlMenu::display(sf::RenderWindow &_window)
{
    _window.clear(sf::Color::Black);
    _window.draw(background.first);
    _window.draw(title);

    for (int i = 0; i < 3; i += 1)
        _window.draw(TLibs[i]);

    for (int i = 0; i < 5; i += 1)
        _window.draw(TGames[i]);
    _window.display();
}

void SfmlMenu::moveCursor(int gameSlc, int graphSlc)
{
    if (gameSlc != slcGame) {
        TGames[slcGame].setFillColor(sf::Color::White);
        slcGame = gameSlc;
        TGames[slcGame].setFillColor(sf::Color::Red);
    }

    if (graphSlc != slcGraph) {
        TLibs[slcGraph].setFillColor(sf::Color::White);
        slcGraph = graphSlc;
        TLibs[slcGraph].setFillColor(sf::Color::Red);
    }
}