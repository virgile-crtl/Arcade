/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** createGraphical
*/

#include "Pacman.hpp"

extern "C" {
    IGame *createGame(){
        return new Pacman();
    }
}