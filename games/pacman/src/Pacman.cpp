/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"

Pacman::Pacman(): _score(0), _win(false)
{
    _enemy.push_back(createEnemy({11, 11}));
    _enemy.push_back(createEnemy({14, 11}));
    _enemy.push_back(createEnemy({15, 12}));
    _enemy.push_back(createEnemy({10, 12}));
}

Pacman::~Pacman()
{
}

std::vector<std::string>& Pacman::start()
{
    _game = getFile("assets/pacman.txt");
    for (int i = 0; i < 4; i++) {
        resetEnemy(_enemy[i], _game);
    }
    _player.pos = {13, 15};
    _player.alive = true;
    _player.target = true;
    _player.mov = nokey;
    return _game;
}

bool Pacman::move(keyType key, int& score)
{
    if (!_win) {
        _player.resetTarget();
        _player.makePlayerMove(_player.getPlayerMov(key, _game), _game, score);
        checkEnemyDeath(_player.pos, _enemy, _game, score);
        _player.alive = enemyActualisation(_game, _enemy, _player.pos, _player.target);
        checkEnemyDeath(_player.pos, _enemy, _game, score);
        _win = checkWin();
    }
    if (_win || !_player.alive)
        return false;
    return true;
}

bool Pacman::checkWin()
{
    for (int i = 0; i < 23; i+= 1) {
        for (int y = 0; y < 27; y += 1) {
            if (_game[i][y] == '.')
                return false;
        }
    }
    return true;
}