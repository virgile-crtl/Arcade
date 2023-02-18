/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** createGraphical
*/

#include "Sfml.hpp"

extern "C" {
    IGraphical *createGraphical(Menu& coreMenu){
        return new Sfml(coreMenu);
    }
}