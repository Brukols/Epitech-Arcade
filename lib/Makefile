##
## EPITECH PROJECT, 2020
## Arcal
## File description:
## Makefile
##

NAME_SFML	=	lib_arcade_sfml.so

NAME_NCURSES	=	lib_arcade_ncurses.so

NAME_SDL	=	lib_arcade_sdl.so

RM	=	rm -f

all: sfml

sfml:
	make -C sfml/
	make -C ncurses/
	make -C sdl/
	mv sfml/$(NAME_SFML) .
	mv ncurses/$(NAME_NCURSES) .
	mv sdl/$(NAME_SDL) .

clean:
	make clean -C sfml/
	make clean -C ncurses/
	make clean -C sdl/

fclean:
	make fclean -C sfml/
	make fclean -C ncurses/
	make fclean -C sdl/
	$(RM) $(NAME_SFML)
	$(RM) $(NAME_NCURSES)
	$(RM) $(NAME_SDL)

re: fclean all

debug:
	make debug -C sfml/
	make debug -C ncurses/
	make debug -C sdl/
	mv sfml/$(NAME_SFML) .
	mv ncurses/$(NAME_NCURSES) .
	mv sdl/$(NAME_SDL) .

.PHONY:	all clean fclean re debug sfml