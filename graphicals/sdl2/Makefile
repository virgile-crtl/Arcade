##
## EPITECH PROJECT, 2022
## arcade
## File description:
## Makefile
##

SRC	=	src/Sdl2.cpp	\
		src/createGraphical.cpp	\
		src/Sdl2Menu.cpp	\
		src/utils.cpp

OBJ =	$(SRC:.cpp=.o)

CPPFLAGS	=	-Iinclude/ -I../include/ -I../../core/include/ -I../../games/include

CXXFLAGS	=	-W -Wall -Wextra -fpic

SDLFLAGS =	-lSDL2 -lSDL2_image -lSDL2_ttf

VFLAGS  =       -g3

CP	=	cp

CC	=	g++ -shared

RM	=	rm -f

NAME	=	arcade_sdl2.so

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(CPPFLAGS) $(SDLFLAGS)
	@$(CP) $(NAME) ../../lib/graph/

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) ../../lib/graph/$(NAME)

re: fclean all

.PHONY:	all clean fclean re