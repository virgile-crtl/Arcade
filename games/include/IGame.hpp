/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <string>
#include <vector>
#include <ctime>
#include "IGraphical.hpp"

class IGame {
    public:
        virtual ~IGame() = default;
        virtual std::vector<std::string>& start() = 0;
        virtual bool move(keyType key, int& score) = 0;
        virtual bool checkWin() = 0;

    protected:
    private:
};

#endif /* !IGAME_HPP_ */
