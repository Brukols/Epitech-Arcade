##
## EPITECH PROJECT, 2020
## Arcal
## File description:
## Makefile
##

all: sfml

sfml:
	make -C sfml/
	make -C ncurses/
	make -C sdl/

clean:
	make clean -C sfml/
	make clean -C ncurses/
	make clean -C sdl/

fclean:
	make fclean -C sfml/
	make fclean -C ncurses/
	make fclean -C sdl/

re: fclean all

debug:
	make debug -C sfml/
	make debug -C ncurses/
	make debug -C sdl/

.PHONY:	all clean fclean re debug sfml