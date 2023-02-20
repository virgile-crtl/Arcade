##
## EPITECH PROJECT, 2022
## arcade
## File description:
## Makefile
##

SRC	=	src/Ncurses.cpp	\
		src/NcursesMenu.cpp	\
		src/utils.cpp	\
		src/createGraphical.cpp

OBJ =	$(SRC:.cpp=.o)

CPPFLAGS	=	-Iinclude/ -I../include -I../../core/include -I../../games/include

CXXFLAGS	=	-W -Wall -Wextra -fpic

NCURSEFLAGS =	-lncurses

VFLAGS  =       -g3

CP	=	cp

CC	=	g++ -shared

RM	=	rm -f

NAME	=	arcade_ncurses.so

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(CPPFLAGS) $(NCURSEFLAGS)
	@$(CP) $(NAME) ../../lib/graph/

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) ../../lib/graph/$(NAME)

re: fclean all

.PHONY:	all clean fclean re