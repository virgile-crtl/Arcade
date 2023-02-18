/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** utils
*/

#include <string.h>
#include "SfmlMenu.hpp"

sf::Text CreateText(sf::Font &font, std::string text, int Size,
sf::Color Color, sf::Uint32 style)
{
    sf::Text myText;
    myText.setFont(font);
    myText.setString(text);
    myText.setCharacterSize(Size);
    myText.setFillColor(Color);
    myText.setStyle(style);
    return myText;
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

std::map<sf::Keyboard::Key, keyType> initEvent()
{
    std::map<sf::Keyboard::Key, keyType> evnt = {
        {sf::Keyboard::Up, up},
        {sf::Keyboard::Down, down},
        {sf::Keyboard::Left, left},
        {sf::Keyboard::Right, right},
        {sf::Keyboard::Escape, quit},
        {sf::Keyboard::Enter, slc},
        {sf::Keyboard::Tab, tab},
        {sf::Keyboard::X, x},
        {sf::Keyboard::W, w},
        {sf::Keyboard::A, a},
        {sf::Keyboard::R, restart},
        {sf::Keyboard::Q, stop}
    };
    return evnt;
}