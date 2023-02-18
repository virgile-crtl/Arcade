##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make
##

DIR_PACMAN	=	pacman

DIR_NIBBLER	=	nibbler

MAKE	=	make

CLEAN	=	make clean

FCLEAN	=	make fclean

RE	=	make re

all:
	@$(MAKE) -C $(DIR_PACMAN)
	@$(MAKE) -C $(DIR_NIBBLER)

clean:
	@$(CLEAN) -C $(DIR_PACMAN)
	@$(CLEAN) -C $(DIR_NIBBLER)

fclean:
	@$(FCLEAN) -C $(DIR_PACMAN)
	@$(FCLEAN) -C $(DIR_NIBBLER)

re:
	@$(RE) -C $(DIR_PACMAN)
	@$(RE) -C $(DIR_NIBBLER)

.PHONY: all clean fclean re
