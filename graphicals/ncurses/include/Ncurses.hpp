/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include "NcursesMenu.hpp"

class Ncurses : public IGraphical {
    public:
        Ncurses(Menu& coreMenu);
        ~Ncurses();

        void refresh();
        void displayGame(std::vector<std::string> game, int score);
        void displayMenu(int gameSlc, int graphSlc);
        void displayScore();
        keyType keyEvent();
        void destroy();

    protected:
    private:
        int _lines;
        int _cols;
        NcursesMenu _ncrMenu;
        std::map<int, keyType> _kEvent;
};

std::map<int, keyType> initEvent();

#endif /* !NCURSES_HPP_ */
