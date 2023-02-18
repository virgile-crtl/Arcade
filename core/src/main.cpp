/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** main
*/

#include "Error.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        print_h();
        return 84;
    }
    try
    {
        Core core(av[1]);
        core.menuLoop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 84;
    }
    return 0;
}