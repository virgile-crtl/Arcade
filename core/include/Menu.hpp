/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** MENU
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Core.hpp"

enum typeLib{
    libgraph,
    libgame,
    unknow
};

struct Menu {
    Menu(std::string& filepath);
    ~Menu();

    std::vector<std::string> getFiles(std::string path) const;
    typeLib checkFile(std::string& filepath) const;
    bool makeEvent(keyType key);

    std::vector<std::string> libsGame;
    std::vector<std::string> libsGraph;
    int slcGame;
    int slcGraph;
};

#endif /* !MENU_HPP_ */
