/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** SfmlMenu
*/

#ifndef SFMLMENU_HPP_
#define SFMLMENU_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Core.hpp"

class SfmlMenu {
    public:
        SfmlMenu(std::vector<std::string>& _libsGame,
        std::vector<std::string>& _libsGraph, int gameSlc, int graphSlc);
        ~SfmlMenu();

        void init();
        void initGames();
        void initGraphs();
        void display(sf::RenderWindow &_window);
        void moveCursor(int gameSlc, int graphSlc);

        std::vector<std::string >& libGames;
        std::vector<std::string >& libGraphs;
        int slcGame;
        int slcGraph;

        sf::Text TLibs[3];
        sf::Text TGames[5];
        std::pair<sf::Sprite, sf::Texture> background;
        sf::Text title;
        sf::Font font;

    protected:
    private:
};

sf::Text CreateText(sf::Font &font, std::string text, int Size,
sf::Color Color, sf::Uint32 style);
void setName(std::string& libname);

#endif /* !SFMLMENU_HPP_ */
