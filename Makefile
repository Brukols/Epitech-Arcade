##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

all:

core:
	make -C core/

clean:
	make clean -C core/

fclean: clean
	make fclean -C core/

re: fclean all

debug: CXXFLAGS	+=	-g
debug: re

.PHONY: all core clean fclean re debug games graphicals