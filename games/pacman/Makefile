##
## EPITECH PROJECT, 2022
## arcade
## File description:
## Makefile
##

SRC	=	src/Pacman.cpp	\
		src/createGame.cpp	\
		src/Player.cpp	\
		src/Enemy.cpp	\
		src/utils.cpp

OBJ =	$(SRC:.cpp=.o)

CPPFLAGS	=	-Iinclude/ -I../include/ -I../../core/include -I../../graphicals/include

CXXFLAGS	=	-W -Wall -Wextra -fpic

VFLAGS  =       -g3

CP	=	cp

CC	=	g++ -shared

RM	=	rm -f

NAME	=	arcade_pacman.so

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
	@$(CP) $(NAME) ../../lib/

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) ../../lib/$(NAME)

re: fclean all

.PHONY:	all clean fclean re