/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

Ncurses::Ncurses(Menu& coreMenu) : _ncrMenu(coreMenu.libsGame,
coreMenu.libsGraph, coreMenu.slcGame, coreMenu.slcGraph), _kEvent(initEvent())
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr, true);
    curs_set(0);
    wrefresh(stdscr);
    getmaxyx(stdscr, _lines, _cols);
    _ncrMenu.lines = _lines;
    _ncrMenu.cols = _cols;
    clear();
}

Ncurses::~Ncurses()
{
    endwin();
}

void Ncurses::refresh()
{
    clear();
}

void Ncurses::displayGame(std::vector<std::string> game, int score)
{
    int l, c;

    getmaxyx(stdscr, l, c);
    if (l != _lines || c != _cols) {
        _lines = l;
        _cols = c;
        clear();
    }
    box(stdscr, 0, 0);
    if (_lines < (int)game.size() + 2 || _cols < (int)game[0].size() + 20) {
        mvwprintw(stdscr, (_lines / 2), ((_cols / 2) - 14),
        "Please resize the terminal!");
    } else {
        for (int i = 0; i < (int)game.size(); i += 1)
            mvwprintw(stdscr, (_lines / 2) - ((game.size() / 2) - i),
                (_cols / 2) - (game[i].size() / 2), game[i].c_str());
        mvwprintw(stdscr, 1, 1, "%d", score);
    }
    wrefresh(stdscr);
}


void Ncurses::displayMenu(int gameSlc, int graphSlc)
{
    _ncrMenu.resizedClear();
    if (_ncrMenu.lines < 20 || _ncrMenu.cols < 30) {
        box(stdscr, 0, 0);
        mvwprintw(stdscr, (_ncrMenu.lines / 2), ((_ncrMenu.cols / 2) - 14),
        "Please resize the terminal!");
    } else
        _ncrMenu.display(gameSlc, graphSlc);
    wrefresh(stdscr);
}


void Ncurses::displayScore()
{
}

keyType Ncurses::keyEvent()
{
    int key = getch();

    if (_kEvent[key])
        return _kEvent[key];
    return nokey;
}

void Ncurses::destroy()
{
}