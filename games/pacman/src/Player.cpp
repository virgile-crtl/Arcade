/*
** EPITECH PROJECT, 2022
** EPITECH
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(): pos({13, 15}), alive(true), target(true)
{
}

Player::~Player()
{
}

void Player::detectTeleportation(std::vector<std::string> &map)
{
    if(pos.first == -1) {
        pos.first = (int)map[1].size();
        map[pos.second][pos.first] = 'P';
    }
    else if(pos.first == (int)map[1].size()) {
        pos.first = 0;
        map[pos.second][pos.first] = 'P';
    }
}

bool Player::canPlayerMove(int newPosX, int newPosY, std::vector<std::string> map)
{
    if (map[newPosY][newPosX] == ' ' || map[newPosY][newPosX] == '.' || map[newPosY][newPosX] == 'o'
        ||  newPosX == -1 || newPosX == (int)map[0].size() || map[newPosY][newPosX] == 'E')
        return true;
    return false;
}

keyType Player::getPlayerMov(keyType key, std::vector<std::string> map)
{
    if (key == up && !canPlayerMove(pos.first, pos.second - 1, map))
        return mov;
    if (key == down && !canPlayerMove(pos.first, pos.second + 1, map))
        return mov;
    if (key == left && !canPlayerMove(pos.first - 1, pos.second, map))
        return mov;
    if (key == right && !canPlayerMove(pos.first + 1, pos.second, map))
        return mov;

    if (key == up || key == down || key == right || (key == left && key != mov))
        mov = key;
    return mov;
}

void Player::movePlayerChar(int newPosX, int newPosY, std::vector<std::string> &map, int &_score)
{
    if (map[newPosY][newPosX] == 'E' && target) {
        map[pos.second][pos.first] = ' ';
        alive = false;
        return;
    }
    if (map[newPosY][newPosX] == '.')
        _score += 10;
    map[pos.second][pos.first] = ' ';

    pos.second = newPosY;
    pos.first = newPosX;
    detectTeleportation(map);
    if (map[pos.second][pos.first] == 'o') {
        target = false;
        targetTime.first = clock();
        targetTime.second = ((float)targetTime.first)/CLOCKS_PER_SEC;
    }
    map[pos.second][pos.first] = 'P';
}

void Player::makePlayerMove(keyType key, std::vector<std::string> &map, int &_score)
{
    animTime.first = clock();
    if (((float)animTime.first)/CLOCKS_PER_SEC >= animTime.second + 0.03 && alive) {
        animTime.second = ((float)animTime.first)/CLOCKS_PER_SEC;
        if (key == up && canPlayerMove(pos.first, pos.second - 1, map))
            movePlayerChar(pos.first, pos.second - 1, map, _score);

        if (key == down && canPlayerMove(pos.first, pos.second + 1, map))
            movePlayerChar(pos.first, pos.second + 1, map, _score);

        if (key == right && canPlayerMove(pos.first + 1, pos.second, map))
            movePlayerChar(pos.first + 1, pos.second, map, _score);

        if (key == left && canPlayerMove(pos.first - 1, pos.second, map))
            movePlayerChar(pos.first - 1, pos.second, map, _score);
    }
}

void Player::resetTarget()
{
    if (!target) {
        targetTime.first = clock();
        if (((float)targetTime.first)/CLOCKS_PER_SEC >= targetTime.second + 1.4)
            target = true;
    }
}