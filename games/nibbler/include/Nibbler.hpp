/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <iostream>
#include <fstream>
#include "IGame.hpp"

class Nibbler : public IGame {
    public:
        Nibbler();
        ~Nibbler();

        std::vector<std::string>& start();
        void addFood();
        bool move(keyType key, int& score);
        bool moveR(int &score);
        bool moveL(int &score);
        bool moveD(int &score);
        bool moveU(int &score);
        void moveEnd();
        bool constMove(keyType prkey, int& score);
        bool checkWin();

    protected:
    private:
        std::vector<std::string> _game;
        std::pair<int, int> _head;
        std::pair<int, int> _end;
        keyType prkey;
        clock_t c;
        float waitTime;
};

std::vector<std::string> getFile(std::string filepath);
std::pair<int, int> getPos(char c, std::vector<std::string>& game);

#endif /* !NIBBLER_HPP_ */
