##
## EPITECH PROJECT, 2022
## arcade
## File description:
## Makefile
##

SRC	=	src/Sfml.cpp	\
		src/createGraphical.cpp	\
		src/SfmlMenu.cpp	\
		src/utils.cpp


OBJ =	$(SRC:.cpp=.o)

CPPFLAGS	=	-Iinclude/ -I../include/ -I../../core/include/ -I../../games/include

CXXFLAGS	=	-W -Wall -Wextra -fpic

VFLAGS  =       -g3

SFMLFLAGS = 	-lsfml-graphics -lsfml-window -lsfml-system

CP	=	cp

CC	=	g++ -shared

RM	=	rm -f

NAME	=	arcade_sfml.so

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(CPPFLAGS) $(SFMLFLAGS)
	@$(CP) $(NAME) ../../lib/graph/

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) ../../lib/graph/$(NAME)

re: fclean all

.PHONY:	all clean fclean re