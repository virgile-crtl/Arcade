/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
{
}

Nibbler::~Nibbler()
{
}

std::vector<std::string>& Nibbler::start()
{
    _game = getFile("assets/nibbler.txt");
    _head = getPos('t', _game);
    _end = getPos('d', _game);
    prkey = nokey;
    waitTime = 0;
    return _game;
}

bool Nibbler::move(keyType key, int& score)
{
    if (prkey == nokey) {
        if (key == right || key == left)
            prkey = up;
         if (key == up || key == down)
            prkey = left;
    }
    if ((prkey == up || prkey == down)
    && (key == right || key == left)) {
        prkey = key;
        if (key == right)
            return moveR(score);
        if (key == left)
            return moveL(score);
    }
    if ((prkey == left || prkey == right)
    && (key == down || key == up)) {
        prkey = key;
        if (key == up)
            return moveU(score);
        if (key == down)
            return moveD(score);
    }
    return constMove(prkey, score);
}

bool Nibbler::constMove(keyType prkey, int& score)
{
    c = clock();
    if (((float)c)/CLOCKS_PER_SEC >= waitTime + 0.15) {
        waitTime = ((float)c)/CLOCKS_PER_SEC;
        if (prkey == right)
            return moveR(score);
        if (prkey == left)
            return moveL(score);
        if (prkey == up)
            return moveU(score);
        if (prkey == down)
            return moveD(score);
    }
    return true;
}

void Nibbler::moveEnd()
{
    if (_game[_end.first][_end.second+1] == 'n') {
        _game[_end.first][_end.second+1] = 'd';
        _game[_end.first][_end.second] = ' ';
        _end.second += 1;
    }
    else if (_game[_end.first][_end.second-1] == 'n') {
        _game[_end.first][_end.second-1] = 'd';
        _game[_end.first][_end.second] = ' ';
        _end.second -= 1;
    }
    else if (_game[_end.first+1][_end.second] == 'n') {
        _game[_end.first+1][_end.second] = 'd';
        _game[_end.first][_end.second] = ' ';
        _end.first += 1;
    }
    else if (_game[_end.first-1][_end.second] == 'n') {
        _game[_end.first-1][_end.second] = 'd';
        _game[_end.first][_end.second] = ' ';
        _end.first -= 1;
    }
}

bool Nibbler::moveR(int &score)
{
    if (_game[_head.first][_head.second+1] == ' '
    || _game[_head.first][_head.second+1] == 'A') {
        if (_game[_head.first][_head.second+1] != 'A')
            moveEnd();
        else {
            score += 1;
            addFood();
        }
        _game[_head.first][_head.second+1] = 't';
        _game[_head.first][_head.second] = 'n';
        _head.second += 1;
        return true;
    }
    return false;
}

bool Nibbler::moveL(int &score)
{
    if (_game[_head.first][_head.second-1] == ' '
    || _game[_head.first][_head.second-1] == 'A') {
        if (_game[_head.first][_head.second-1] != 'A')
            moveEnd();
        else {
            score += 1;
            addFood();
        }
        _game[_head.first][_head.second-1] = 't';
        _game[_head.first][_head.second] = 'n';
        _head.second -= 1;
        return true;
    }
    return false;
}

bool Nibbler::moveD(int &score)
{
    if (_game[_head.first+1][_head.second] == ' '
    || _game[_head.first+1][_head.second] == 'A') {
        if (_game[_head.first+1][_head.second] != 'A')
            moveEnd();
        else {
            score += 1;
            addFood();
        }
        _game[_head.first+1][_head.second] = 't';
        _game[_head.first][_head.second] = 'n';
        _head.first += 1;
        return true;
    }
    return false;
}

bool Nibbler::moveU(int& score)
{
    if (_game[_head.first-1][_head.second] == ' '
    || _game[_head.first-1][_head.second] == 'A') {
        if (_game[_head.first-1][_head.second] != 'A')
            moveEnd();
        else {
            score += 1;
            addFood();
        }
        _game[_head.first-1][_head.second] = 't';
        _game[_head.first][_head.second] = 'n';
        _head.first -= 1;
        return true;
    }
    return false;
}

void Nibbler::addFood()
{
    int y = rand()%_game.size();
    int x = rand()%_game[y].size();

    if (_game[y][x] == ' ')
        _game[y][x] = 'A';
    else
        addFood();
}

bool Nibbler::checkWin()
{
    for (int y = 0; y < (int)_game.size(); y += 1)
        for (int x = 0; x < (int)_game[y].size(); x += 1)
            if (_game[y][x] == ' ')
                return false;
    return true;
}