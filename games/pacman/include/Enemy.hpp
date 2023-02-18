/*
** EPITECH PROJECT, 2022
** EPITECH
** File description:
** Enemy
*/

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "IGame.hpp"

class Enemy {
    public:
        Enemy();
        ~Enemy();

        std::pair<int , int> refPos;
        std::pair<clock_t, float> animTime;
        std::pair<clock_t, float> clockStart;
        bool alive;
        bool target;
        bool start;
        int chance;
        char before;
        bool onPlayer;
        std::pair<int, int> pos;
        std::pair<int, int> startPos;
        keyType mov;

    protected:
    private:
};
bool canEnemyMove(std::pair<int, int> newPos, std::vector<std::string> &map, Enemy &_enemy);
void movEnemyChar(std::pair<int, int> newPos, Enemy &_enemy, std::vector<std::string> &map, std::pair<int, int> refP);
Enemy createEnemy(std::pair<int, int> Pos);
bool movEnemyFromRand(keyType key, std::vector<std::string> &map, Enemy &_enemy, std::pair<int, int> refP);
bool canMovToTarget(std::vector<std::string> &map, Enemy &_enemy, std::pair<int, int> refP);
std::pair<int, int> getPlayerPosInverse(std::pair<int, int> playerPos);
void resetEnemy(Enemy &_enemy, std::vector<std::string> &map);
void checkEnemyDeath(std::pair<int, int> Ppos, std::vector<Enemy> &_enemy, std::vector<std::string> &map, int &score);
void checkEnemyTarget(bool pTarget, std::vector<Enemy> &_enemy, std::pair<int, int> refP);
std::pair<int, int> getIndex(Enemy &_enemy);
bool moveEnemy(Enemy &_enemy, std::vector<std::string> &map, std::pair<int, int> refP, std::pair<int ,int> index);
bool enemyActualisation(std::vector<std::string> &map, std::vector<Enemy> &_enemy, std::pair<int, int> refP, bool &pTarget);

#endif /* !ENEMY_HPP_ */
