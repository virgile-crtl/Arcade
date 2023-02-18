/*
** EPITECH PROJECT, 2022
** EPITECH
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "IGame.hpp"

class Player {
    public:
        Player();
        ~Player();
        bool canPlayerMove(int newPosX, int newPosY, std::vector<std::string> map);
        keyType getPlayerMov(keyType key, std::vector<std::string> map);
        void movePlayerChar(int newPosX, int newPosY, std::vector<std::string> &map, int &_score);
        void makePlayerMove(keyType key, std::vector<std::string> &map, int &_score);
        void resetTarget();
        void detectTeleportation(std::vector<std::string> &map);

        std::pair<int, int> pos;
        std::pair<clock_t, float> animTime;
        std::pair<clock_t, float> targetTime;
        bool alive;
        bool target;
        keyType mov;

    protected:
    private:
};

#endif /* !PLAYER_HPP_ */
