/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** createGraphical
*/

#include "Ncurses.hpp"

extern "C" {
    IGraphical *createGraphical(Menu& coreMenu){
        return new Ncurses(coreMenu);
    }
}