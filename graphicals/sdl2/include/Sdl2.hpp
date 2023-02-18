/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Sdl2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "Sdl2Menu.hpp"

class Sdl2 : public IGraphical{
    public:
        Sdl2(Menu& coreMenu);
        ~Sdl2();

        void refresh();
        void displayGame(std::vector<std::string> game, int score);
        void displayMenu(int gameSlc, int graphSlc);
        void displayScore();
        keyType keyEvent();
        void destroy();
        void initTexture();

    protected:
    private:
        Sdl2Menu _sdl2Menu;
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        std::map<SDL_Keycode, keyType> _kEvent;
        std::map<char, SDL_Texture *> _texture;
};

std::map<SDL_Keycode, keyType> initEvent();

#endif /* !SDL2_HPP_ */
