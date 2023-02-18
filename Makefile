##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make
##

DIR_CORE	=	core

DIR_GAMES	=	games

DIR_GRAPHICALS	=	graphicals

MAKE	=	make

CLEAN	=	make clean

FCLEAN	=	make fclean

RE	=	make re

all:
	@$(MAKE) -sC $(DIR_CORE)
	@$(MAKE) -sC $(DIR_GAMES)
	@$(MAKE) -sC $(DIR_GRAPHICALS)

core:
	@$(MAKE) -sC $(DIR_CORE)

games:
	@$(MAKE) -sC $(DIR_GAMES)

graphicals:
	@$(MAKE) -sC $(DIR_GRAPHICALS)

clean:
	@$(CLEAN) -sC $(DIR_CORE)
	@$(CLEAN) -sC $(DIR_GAMES)
	@$(CLEAN) -sC $(DIR_GRAPHICALS)

fclean:
	@$(FCLEAN) -sC $(DIR_CORE)
	@$(FCLEAN) -sC $(DIR_GAMES)
	@$(FCLEAN) -sC $(DIR_GRAPHICALS)

re:
	@$(RE) -sC $(DIR_CORE)
	@$(RE) -sC $(DIR_GAMES)
	@$(RE) -sC $(DIR_GRAPHICALS)

.PHONY: all clean fclean re core graphicals games
