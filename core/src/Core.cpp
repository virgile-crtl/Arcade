/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(std::string filepath) :  _menu(filepath), _score(0)
{
    _handleGraph = dlopen(
        _menu.libsGraph[_menu.slcGraph].c_str(), RTLD_LAZY);
    IGraphical *(*createGraphical)(Menu&) = (IGraphical *(*)(Menu&))dlsym(_handleGraph, "createGraphical");
    _actGraph = createGraphical(_menu);
}

Core::~Core()
{
    _actGraph->~IGraphical();
    dlclose(_handleGraph);
}

void Core::menuLoop()
{
    bool open = true;
    keyType key;
    int gr = _menu.slcGraph;

    while(open) {
        _actGraph->displayMenu(_menu.slcGame, _menu.slcGraph);
        key = _actGraph->keyEvent();
        if (key == slc) {
            gameLoop();
            continue;
        }
        open = _menu.makeEvent(key);
        if (gr != _menu.slcGraph) {
            gr = _menu.slcGraph;
            loadGraph();
        }
    }
}

int Core::gameLoop()
{
    bool open = true;
    int ga =_menu.slcGame;
    keyType key = nokey;
    loadGame();
    std::vector<std::string>& _game = _actGame->start();

    _actGraph->refresh();
    while (open) {
        _actGraph->displayGame(_game, _score);
        if (_actGame->checkWin())
            break;
        key = _actGraph->keyEvent();
        if (key == stop)
            exit(0);
        if (key == quit)
            break;
        if (key == restart) {
            _score = 0;
            _game = _actGame->start();
            _actGraph->refresh();
            continue;
        }
        makeEvent(key);
        if (ga != _menu.slcGame) {
            ga = _menu.slcGame;
            _game = reloadGame();
            continue;
        }
        open = _actGame->move(key, _score);
    }
    _score = 0;
    _actGame->~IGame();
    dlclose(_handleGame);
    _actGraph->refresh();
    return 0;
}

std::vector<std::string>& Core::reloadGame()
{
    _score = 0;
    _actGame->~IGame();
    dlclose(_handleGame);
    loadGame();
    _actGraph->refresh();
    return _actGame->start();
}

void Core::loadGame()
{
    _handleGame = dlopen(
        _menu.libsGame[_menu.slcGame].c_str(), RTLD_LAZY);
    IGame *(*createGame)() = (IGame *(*)())dlsym(_handleGame, "createGame");
    _actGame = createGame();
}

void Core::loadGraph()
{
    _actGraph->~IGraphical();
    dlclose(_handleGraph);
    _handleGraph = dlopen(
        _menu.libsGraph[_menu.slcGraph].c_str(), RTLD_LAZY);
    IGraphical *(*createGraphical)(Menu&) = (IGraphical *(*)(Menu&))dlsym(_handleGraph, "createGraphical");
    _actGraph = createGraphical(_menu);
}

void Core::makeEvent(keyType key)
{
    if (key == w) {
        if (_menu.slcGame - 1 < 0)
            _menu.slcGame = _menu.libsGame.size() - 1;
        else
            _menu.slcGame -= 1;
    }
    if (key == x) {
        if (_menu.slcGame + 1 >= (int)_menu.libsGame.size())
            _menu.slcGame = 0;
        else
            _menu.slcGame += 1;
    }
    if (key == a) {
        if (_menu.slcGraph + 1 >= (int)_menu.libsGraph.size())
            _menu.slcGraph = 0;
        else
            _menu.slcGraph += 1;
        loadGraph();
    }
    if (key == tab) {
        if (_menu.slcGraph - 1 < 0)
            _menu.slcGraph = _menu.libsGraph.size() - 1;
        else
            _menu.slcGraph -= 1;
        loadGraph();
    }
}
