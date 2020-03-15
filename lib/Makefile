##
## EPITECH PROJECT, 2020
## Arcal
## File description:
## Makefile
##

NAME_SFML	=	lib_arcade_sfml.so

NAME_NCURSES	=	lib_arcade_ncurses.so

RM	=	rm -f

all: sfml

sfml:
	make -C sfml/
	make -C ncurses/
	mv sfml/$(NAME_SFML) .
	mv ncurses/$(NAME_NCURSES) .

clean:
	make clean -C sfml/
	make clean -C ncurses/

fclean: clean
	make fclean -C sfml/
	make fclean -C ncurses/
	$(RM) $(NAME_SFML)
	$(RM) $(NAME_NCURSES)

re: fclean all

debug:
	make debug -C sfml/
	make debug -C ncurses/

.PHONY:	all clean fclean re debug sfml