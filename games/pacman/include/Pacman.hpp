/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "Player.hpp"
#include "Enemy.hpp"

class Pacman : public IGame{
    public:
        Pacman();
        ~Pacman();

        std::vector<std::string>& start();
        bool move(keyType key, int& score);
        bool checkWin();

    protected:
    private:
        std::vector<std::string> _game;
        std::vector<Enemy> _enemy;
        std::pair<int, int> _mapSize;
        Player _player;
        int _score;
        bool _win;
};

std::vector<std::string> getFile(std::string filepath);

#endif /* !PACMAN_HPP_ */
