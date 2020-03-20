##
## EPITECH PROJECT, 2020
## Arcade - Pacman
## File description:
## Makefile
##

NAME_PACMAN	=	lib_arcade_pacman.so

SRCS_PACMAN	=	src/Pacman.cpp	\
				src/InitPacman.cpp	\
				src/Gameplay.cpp

OBJS	=	$(SRCS_PACMAN:.cpp=.o)

OBJS_TEST	=	$(SRCS_PACMAN:.cpp=.gcno) $(SRCS_PACMAN:.cpp=.gcda)

CXXFLAGS	=	-I./include -I../../include -W -Wall -Wextra -std=c++17 -fPIC

LDFLAGS		=	\

CC	=	g++

RM	=	rm -f

all: $(NAME_PACMAN)

$(NAME_PACMAN): $(OBJS)
	$(CC) -shared -o $(NAME_PACMAN) $(OBJS)
	mv $(NAME_PACMAN) ../

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_TEST)

fclean: clean
	$(RM) ../$(NAME_PACMAN)

re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY:	all clean fclean re debug