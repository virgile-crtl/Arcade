/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "SfmlMenu.hpp"

class Sfml : public IGraphical{
    public:
        Sfml(Menu& coreMenu);
        ~Sfml();

        void refresh();
        void displayGame(std::vector<std::string> game, int score);
        void displayMenu(int slcGame, int slcGraph);
        void displayScore();
        keyType keyEvent();
        void destroy();
        void initTexture();
        void setTexture(std::vector<std::string> game);

    protected:
    private:
        SfmlMenu _sfmlMenu;
        sf::RenderWindow _window;
        std::map<sf::Keyboard::Key, keyType> _kEvent;
        std::map<char, std::pair<sf::Sprite, sf::Texture>> _texture;
};
std::map<sf::Keyboard::Key, keyType> initEvent();

#endif /* !SFML_HPP_ */
