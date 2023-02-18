/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** NcursesMenu
*/

#include "Ncurses.hpp"

NcursesMenu::NcursesMenu(std::vector<std::string>& _libsGame, std::vector<std::string>& _libsGraph, int gameSlc, int graphSlc)
: lines(0) , cols(0), slcGame(gameSlc), slcGraph(graphSlc), libsGame(_libsGame), libsGraph(_libsGraph)
{
}

NcursesMenu::~NcursesMenu()
{
}

void NcursesMenu::resizedClear()
{
    int tmpCols = cols;
    int tmpLines = lines;

    getmaxyx(stdscr, lines, cols);
    if (lines != tmpLines || cols != tmpCols)
        clear();
}

void NcursesMenu::display(int gameSlc, int graphSlc)
{
    int space = 2;
    int i = 0;

    if (gameSlc != slcGame || graphSlc != slcGraph) {
        clear();
        slcGame = gameSlc;
        slcGraph = graphSlc;
    }
    box(stdscr, 0, 0);
    mvwprintw(stdscr, 0, (cols / 2) - 3, "Arcade");
    for (std::string tmp : libsGraph) {
        setName(tmp);
        tmp.push_back(' ');
        tmp.push_back('/');
        mvwprintw(stdscr, 1, space, tmp.c_str());
        if (i == slcGraph)
            mvwprintw(stdscr, 2, (space + (tmp.size() / 2) -1), "*");
        space += tmp.size() + 1;
        i += 1;
    }
    space = 0;
    for (std::string tmp : libsGame) {
        setName(tmp);
        if (space / 2 == slcGame)
             mvwprintw(stdscr, ((lines / 2) - libsGame.size() + space),
            ((cols / 2) - (tmp.size() / 2) - 3), "->");
        mvwprintw(stdscr, ((lines / 2) - libsGame.size() + space),
        ((cols / 2) - (tmp.size() / 2)), tmp.c_str());
        space += 2;
    }
}