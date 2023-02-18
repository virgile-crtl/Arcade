/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** utils
*/
#include "Pacman.hpp"
#include <iostream>
#include <fstream>

std::vector<std::string> getFile(std::string filepath)
{
    std::vector<std::string> file;
    std::ifstream inpt(filepath, std::ios::in);
    std::string line;

    for (int i = 0; getline(inpt, line); i += 1)
        file.push_back(line);
    inpt.close();
    return file;
}