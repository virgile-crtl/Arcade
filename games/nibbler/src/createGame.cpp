/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** createGraphical
*/

#include "Nibbler.hpp"

extern "C" {
    IGame *createGame(){
        return new Nibbler();
    }
}