##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

CORE_NAME	=	arcade

RM	=	rm -f

all: core graphicals games

core:
	make -C core/
	mv core/$(CORE_NAME) .

graphicals:
	make -C lib/

games:
	make -C games/

clean:
	make clean -C core/
	make clean -C lib/
	make clean -C games/

fclean:
	make fclean -C core/
	make fclean -C lib/
	make fclean -C games/
	$(RM) $(CORE_NAME)

re: fclean all

debug:
	make debug -C core/
	make debug -C lib/
	make debug -C games/
	mv core/$(CORE_NAME) .

.PHONY: all core clean fclean re debug games graphicals