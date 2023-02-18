/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_
#include <map>

enum keyType {
    up = 1,
    down = 2,
    left = 3,
    right = 4,
    quit = 5,
    slc = 6,
    nokey = 7,
    tab = 8,
    a = 9,
    x = 10,
    w = 11,
    restart = 12,
    stop = 13,
    k = 14
};

class IGraphical {
    public:
        virtual ~IGraphical() = default;
        virtual void refresh() = 0;
        virtual void displayGame(std::vector<std::string> game, int score) = 0;
        virtual void displayMenu(int gameSlc, int graphSlc) = 0;
        virtual void displayScore() = 0;
        virtual keyType keyEvent() = 0;
        virtual void destroy() = 0;

    protected:
    private:
};

#endif /* !IGRAPHICAL_HPP_ */
