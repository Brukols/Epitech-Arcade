##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

CORE_NAME	=	arcade

RM	=	rm -f

all: core

core:
	make -C core/
	mv core/$(CORE_NAME) .

clean:
	make clean -C core/

fclean: clean
	make fclean -C core/
	$(RM) $(CORE_NAME)

re: fclean all

debug: CXXFLAGS	+=	-g
debug: re

.PHONY: all core clean fclean re debug games graphicals