/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** utils
*/

#include "Nibbler.hpp"

std::pair<int, int> getPos(char c, std::vector<std::string>& map)
{
    for (int y = 0; y < (int)map.size(); y += 1)
        for(int x = 0; x < (int)map[y].size(); x += 1)
            if (c == map[y][x])
                return std::make_pair(y, x);
    return std::make_pair(-1, -1);
}

std::vector<std::string> getFile(std::string filepath)
{
    std::vector<std::string> file;
    std::ifstream inpt(filepath, std::ios::in);
    std::string line;

    for (int i = 0; getline(inpt, line); i += 1)
        file.push_back(line);
    inpt.close();
    return file;
}