##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make
##

DIR_NCURSES	=	ncurses

DIR_SDL2	=	sdl2

DIR_SFML	=	sfml

MAKE	=	make

CLEAN	=	make clean

FCLEAN	=	make fclean

RE	=	make re

all:
	@$(MAKE) -C $(DIR_NCURSES)
	@$(MAKE) -C $(DIR_SDL2)
	@$(MAKE) -C $(DIR_SFML)

clean:
	@$(CLEAN) -C $(DIR_NCURSES)
	@$(CLEAN) -C $(DIR_SDL2)
	@$(CLEAN) -C $(DIR_SFML)

fclean:
	@$(FCLEAN) -C $(DIR_NCURSES)
	@$(FCLEAN) -C $(DIR_SDL2)
	@$(FCLEAN) -C $(DIR_SFML)

re:
	@$(RE) -C $(DIR_NCURSES)
	@$(RE) -C $(DIR_SDL2)
	@$(RE) -C $(DIR_SFML)

.PHONY: all clean fclean re
