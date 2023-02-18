##
## EPITECH PROJECT, 2022
## arcade
## File description:
## Makefile
##

SRC	=	src/main.cpp	\
		src/Error.cpp	\
		src/Menu.cpp	\
		src/Core.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS	=	-Iinclude/ -I../graphicals/include -I../games/include -std=c++17

CXXFLAGS	=	-W -Wall -Wextra

DLFLAGS	=	-ldl

VFLAGS  =       -g3

CC	=	g++

CP 	=	cp

RM	=	rm -f

NAME	=	arcade

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(CPPFLAGS) $(DLFLAGS)
	@$(CP) $(NAME) ../

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) ../$(NAME)

re: fclean all

.PHONY:	all clean fclean re