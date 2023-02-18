/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** createGraphical
*/

#include "Sdl2.hpp"

extern "C" {
    IGraphical *createGraphical(Menu& coreMenu){
        return new Sdl2(coreMenu);
    }
}