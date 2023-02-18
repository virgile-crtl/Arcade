/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** NcursesMenu
*/

#ifndef NCURSESMENU_HPP_
#define NCURSESMENU_HPP_

#include "Core.hpp"

struct NcursesMenu {
    public:
        NcursesMenu(std::vector<std::string>& _libsGame, std::vector<std::string>& _libsGraph, int gameSlc, int graphSlc);
        ~NcursesMenu();

        void resizedClear();
        void display(int gameSlc, int graphSlc);

        int lines;
        int cols;
        int slcGame;
        int slcGraph;
        std::vector<std::string>& libsGame;
        std::vector<std::string>& libsGraph;

    protected:
    private:
};

void setName(std::string& name);

#endif /* !NCURSESMENU_HPP_ */
