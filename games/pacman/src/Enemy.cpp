/*
** EPITECH PROJECT, 2022
** EPITECH
** File description:
** Enemy
*/

#include "Enemy.hpp"

Enemy::Enemy(): refPos(13, 9), animTime(0, 0), clockStart(0, 0), alive(false), target(false), start(false), chance(0), before(' '), onPlayer(false)
{
}

Enemy::~Enemy()
{
}

bool canEnemyMove(std::pair<int, int> newPos, std::vector<std::string> &map, Enemy &_enemy)
{
    if (map[newPos.second][newPos.first] == ' ' || map[newPos.second][newPos.first] == '.'
        || map[newPos.second][newPos.first] == 'O' || (map[newPos.second][newPos.first] == 'P' && !_enemy.target)
        || (map[newPos.second][newPos.first] == 'S' && !_enemy.start))
        return true;
    return false;
}

void movEnemyChar(std::pair<int, int> newPos, Enemy &_enemy, std::vector<std::string> &map, std::pair<int, int> refP)
{
   if ((_enemy.pos.first == _enemy.refPos.first ||_enemy.pos.first == _enemy.refPos.first + 1
    || _enemy.pos.first == _enemy.refPos.first - 1) && _enemy.pos.second == _enemy.refPos.second && !_enemy.start) {
        _enemy.refPos = {refP.first, refP.second};
        _enemy.start = true;
    }
    if (map[newPos.second][newPos.first] == 'P' && !_enemy.target) {
        _enemy.onPlayer = true;
    }
    map[_enemy.pos.second][_enemy.pos.first] = _enemy.before;
    _enemy.pos.second = newPos.second;
    _enemy.pos.first = newPos.first;
    if (map[_enemy.pos.second][_enemy.pos.first] == 'P' && _enemy.target) {
        return;
    }
    _enemy.before = map[_enemy.pos.second][_enemy.pos.first];
    map[_enemy.pos.second][_enemy.pos.first] = 'E';
}

Enemy createEnemy(std::pair<int, int> Pos)
{
    Enemy myEnemy;
    myEnemy.pos = Pos;
    myEnemy.startPos = Pos;
    return myEnemy;
}

bool movEnemyFromRand(keyType key, std::vector<std::string> &map, Enemy &_enemy, std::pair<int, int> refP)
{
    if (key == up && canEnemyMove({_enemy.pos.first, _enemy.pos.second - 1}, map, _enemy)) {
        movEnemyChar({_enemy.pos.first, _enemy.pos.second - 1}, _enemy, map, refP);
        return true;
    }
    if (key == down && canEnemyMove({_enemy.pos.first, _enemy.pos.second + 1}, map, _enemy) && _enemy.before != 'S') {
        movEnemyChar({_enemy.pos.first, _enemy.pos.second + 1}, _enemy, map, refP);
        return true;
    }
    if (key == left && canEnemyMove({_enemy.pos.first - 1, _enemy.pos.second}, map, _enemy)) {
        movEnemyChar({_enemy.pos.first - 1, _enemy.pos.second}, _enemy, map, refP);
        return true;
    }
    if (key == right && canEnemyMove({_enemy.pos.first + 1, _enemy.pos.second}, map, _enemy)) {
        movEnemyChar({_enemy.pos.first + 1, _enemy.pos.second}, _enemy, map, refP);
        return true;
    }
    return false;
}

bool canMovToTarget(std::vector<std::string> &map, Enemy &_enemy, std::pair<int, int> refP)
{
    std::pair<keyType, keyType> keyDir;
    int r;

    if (_enemy.pos.first < _enemy.refPos.first)
        keyDir.first = right;
    if (_enemy.pos.first > _enemy.refPos.first)
        keyDir.first = left;
    if (_enemy.pos.second < _enemy.refPos.second)
        keyDir.second = down;
    if (_enemy.pos.second > _enemy.refPos.second)
        keyDir.second = up;

    r = rand() % 2 + 1;
    if (r == 1)
        return movEnemyFromRand(keyDir.first, map, _enemy, refP);
    else
        return movEnemyFromRand(keyDir.second, map, _enemy, refP);
    return false;
}

std::pair<int, int> getPlayerPosInverse(std::pair<int, int> playerPos)
{
    std::pair<int, int> newPos;

    if (playerPos.first <= 14)
        newPos.first = rand() % 28 + 15;
    else
        newPos.first = rand() % 1 + 14;

    if (playerPos.second <= 11)
        newPos.first = rand() % 23 + 12;
    else
        newPos.first = rand() % 1 + 11;
    return newPos;
}

void resetEnemy(Enemy &_enemy, std::vector<std::string> &map)
{
    _enemy.alive = false;
    _enemy.pos = _enemy.startPos;
    _enemy.refPos = {13, 9};
    _enemy.start = false;
    _enemy.target = false;
    _enemy.before = ' ';
    _enemy.clockStart.first = clock();
    _enemy.clockStart.second = ((float)_enemy.clockStart.first)/CLOCKS_PER_SEC;
    map[_enemy.pos.second][_enemy.pos.first] = 'E';
}

void checkEnemyDeath(std::pair<int, int> Ppos, std::vector<Enemy> &_enemy, std::vector<std::string> &map, int &score)
{
    for (int i = 0; i < 4; i+= 1) {
        if (_enemy[i].pos.first == Ppos.first
            && _enemy[i].pos.second == Ppos.second && _enemy[i].target) {
                score += 50;
                resetEnemy(_enemy[i], map);
            }
    }
}

void checkEnemyTarget(bool pTarget, std::vector<Enemy> &_enemy, std::pair<int, int> refP)
{
    for (int i = 0; i < 4; i += 1) {
        if (pTarget)
            _enemy[i].target = false;
        if (pTarget && _enemy[i].start)
            _enemy[i].refPos = refP;
        if (!pTarget && _enemy[i].start) {
            _enemy[i].target = true;
            _enemy[i].refPos = getPlayerPosInverse(refP);
        }
    }
}

std::pair<int, int> getIndex(Enemy &_enemy)
{
    int key = rand() % 4 + 1;
    std::pair<int, int> index = {0, 0};

    if (key == 1) {
        _enemy.mov = up;
        index.second = -1;
    }
    if (key == 2) {
        _enemy.mov = down;
        index.second = 1;
    }
    if (key == 3) {
        _enemy.mov = left;
        index.first = -1;
    }
    if (key == 4) {
        _enemy.mov = right;
        index.first = 1;
    }
    return index;
}

bool moveEnemy(Enemy &_enemy, std::vector<std::string> &map, std::pair<int, int> refP, std::pair<int ,int> index)
{
    _enemy.animTime.first = clock();
    if (((float)_enemy.animTime.first)/CLOCKS_PER_SEC >= _enemy.animTime.second + 0.03 && _enemy.alive) {
        _enemy.animTime.second = ((float)_enemy.animTime.first)/CLOCKS_PER_SEC;

        _enemy.chance += 1;
        index = getIndex(_enemy);
        if (!canMovToTarget(map, _enemy, refP)) {
            if (canEnemyMove({_enemy.pos.first + index.first, _enemy.pos.second + index.second}, map, _enemy))
                movEnemyChar({_enemy.pos.first + index.first, _enemy.pos.second + index.second}, _enemy, map, refP);
        }
        else {
            if (canEnemyMove({_enemy.pos.first + index.first, _enemy.pos.second + index.second}, map, _enemy)) {
                movEnemyChar({_enemy.pos.first + index.first, _enemy.pos.second + index.second}, _enemy, map, refP);
            }
            else
                return false;
        }
    }
    return true;
}

bool enemyActualisation(std::vector<std::string> &map, std::vector<Enemy> &_enemy, std::pair<int, int> refP, bool &pTarget)
{
    srand(time(NULL));
    std::pair<int, int> index;
    checkEnemyTarget(pTarget, _enemy, refP);

    for (int i = 0; i < 4; i += 1) {

        _enemy[i].clockStart.first = clock();
        if (((float)_enemy[i].clockStart.first)/CLOCKS_PER_SEC >= _enemy[i].clockStart.second + 1.4 && !_enemy[i].alive)
            _enemy[i].alive = true;
        if (!moveEnemy(_enemy[i], map, refP, index))
            i-= 1;
        if (_enemy[i].chance == 3)
            i += 1;
    }
    for (int i = 0; i < 4; i+=1) {
        _enemy[i].chance = 0;
        if (_enemy[i].onPlayer) {
            return false;
        }
    }
    return true;
}