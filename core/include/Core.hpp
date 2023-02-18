/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <algorithm>
#include <dlfcn.h>
#include <iostream>
#include <map>
#include <vector>
#include "IGraphical.hpp"
#include "IGame.hpp"
#include "Menu.hpp"

class Core {
    public:
        Core(std::string filepath);
        ~Core();

        void menuLoop();
        int gameLoop();
        void loadGraph();
        void loadGame();
        void makeEvent(keyType key);
        std::vector<std::string>& reloadGame();

    protected:
    private:
        Menu _menu;
        void *_handleGraph;
        void *_handleGame;
        IGraphical *_actGraph;
        IGame *_actGame;
        int _score;
};

#endif /* !CORE_HPP_ */