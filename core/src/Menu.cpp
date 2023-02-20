/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Elem
*/

#include <filesystem>
#include "Error.hpp"

Menu::Menu(std::string& filepath)
{
    std::vector<std::string> files = getFiles("lib/game/");
    std::vector<std::string> gr = getFiles("lib/graph/");
    typeLib typeFile;

    files.insert(files.end(), gr.begin(), gr.end());
    if (checkFile(filepath) != libgraph)
        throw Error(filepath+": not a grahical library.");
    libsGraph.push_back(filepath);
    for (std::string tmp : files) {
        if (tmp == filepath)
            continue;
        typeFile = checkFile(tmp);
        if (typeFile == libgraph)
            libsGraph.push_back(tmp);
        else if (typeFile == libgame)
            libsGame.push_back(tmp);
    }
    slcGraph = 0;
    slcGame = 0;
}

Menu::~Menu()
{
}

std::vector<std::string> Menu::getFiles(std::string path) const
{
    std::vector<std::string> files;
    for (const auto &file : std::filesystem::directory_iterator{path})
        files.push_back(file.path());
    return files;
}

typeLib Menu::checkFile(std::string& filepath) const
{
    void *lib = dlopen(filepath.c_str(), RTLD_LAZY);
    if (!lib) {
        return unknow;
    }
    dlsym(lib, "createGraphical");
    if (dlerror() == NULL) {
        dlclose(lib);
        return libgraph;
    }
    dlsym(lib, "createGame");
    if (dlerror() == NULL) {
        dlclose(lib);
        return libgame;
    }
    dlclose(lib);
    return unknow;
}

bool Menu::makeEvent(keyType key)
{
    if (key == up) {
        if (slcGame - 1 < 0)
            slcGame = libsGame.size() - 1;
        else
            slcGame -= 1;
    }
    if (key == down) {
        if (slcGame + 1 >= (int)libsGame.size())
            slcGame = 0;
        else
            slcGame += 1;
    }
    if (key == quit) {
        return false;
    }
    if (key == a) {
        if (slcGraph + 1 >= (int)libsGraph.size())
            slcGraph = 0;
        else
            slcGraph += 1;
    }
    if (key == tab) {
        if (slcGraph - 1 < 0)
            slcGraph = libsGraph.size() - 1;
        else
            slcGraph -= 1;
    }
    return true;
}