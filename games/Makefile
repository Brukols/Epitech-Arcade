##
## EPITECH PROJECT, 2020
## Arcade - Game
## File description:
## Makefile
##

DIR_NIBBLER = ./nibbler/

DIR_PACMAN = ./pacman/

all:
	make -C $(DIR_NIBBLER)
	make -C $(DIR_PACMAN)

clean:
	make -C $(DIR_NIBBLER) clean
	make -C $(DIR_PACMAN) clean

fclean: clean
	make -C $(DIR_NIBBLER) fclean
	make -C $(DIR_PACMAN) fclean

re: fclean all

debug:
	make -C $(DIR_NIBBLER) debug
	make -C $(DIR_PACMAN) debug

.PHONY:	all clean fclean re debug