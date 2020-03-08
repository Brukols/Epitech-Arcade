##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

CORE_NAME	=	arcade

RM	=	rm -f

all: core graphicals

core:
	make -C core/
	mv core/$(CORE_NAME) .

graphicals:
	make -C lib/

clean:
	make clean -C core/
	make clean -C lib/

fclean: clean
	make fclean -C core/
	make fclean -C lib/
	$(RM) $(CORE_NAME)

re: fclean all

debug:
	make debug -C core/
	make debug -C lib/
	mv core/$(CORE_NAME) .

.PHONY: all core clean fclean re debug games graphicals