/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** utils
*/

#include <string.h>
#include "Ncurses.hpp"

void setName(std::string& libname)
{
    libname = strrchr(libname.c_str(), '/');
    libname.erase(libname.begin());
    reverse(libname.begin(), libname.end());
    libname = strchr(libname.c_str(), '.');
    libname.erase(libname.begin());
    reverse(libname.begin(), libname.end());
}

std::map<int, keyType> initEvent()
{
    std::map<int, keyType> evnt = {
        {259, up},
        {258, down},
        {260, left},
        {261, right},
        {10, slc},
        {27, quit},
        {9, tab},
        {120, x},
        {119, w},
        {97, a},
        {114, restart},
        {113, stop}
    };
    return evnt;
}