##
## EPITECH PROJECT, 2020
## Arcal
## File description:
## Makefile
##

NAME_SFML	=	lib_arcade_sfml.so

RM	=	rm -f

all: sfml

sfml:
	make -C sfml/
	mv sfml/$(NAME_SFML) .

clean:
	make clean -C sfml/

fclean: clean
	make fclean -C sfml/
	$(RM) $(NAME_SFML)

re: fclean all

debug:
	make debug -C sfml/

.PHONY:	all clean fclean re debug sfml