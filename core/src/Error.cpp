/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(const std::string message) : _message(message)
{
}

Error::~Error()
{
}

const char *Error::what() const noexcept
{
    return _message.c_str();
}

void print_h(void)
{
    std::cout << "USAGE:\n\t./arcade option\n\nOPTION:" << std::endl;
    std::cout << "\t./lib/arcade_sfml.so\tuse sfml graphics" << std::endl;
    std::cout << "\t./lib/arcade_sdl2.so\tuse sdl2 graphics" << std::endl;
    std::cout << "\t./lib/arcade_ncurses.so\tuse ncurses graphics" << std::endl;
}
