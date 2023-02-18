/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include "Core.hpp"

class Error : public std::exception {
    public:
        Error(const std::string message = "Error");
        ~Error();

        const char *what() const noexcept;
    protected:
    private:
        const std::string _message;
};

void print_h(void);

#endif /* !ERROR_HPP_ */
