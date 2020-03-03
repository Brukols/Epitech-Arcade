##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

NAME	=	arcade

NAME_GAME_PACMAN	=	lib_arcade_pacman.so

NAME_LIB_NCURSES		=	lib_arcade_ncurses.so

SRCS	=	src/main.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

OBJS_COV	=	$(SRCS:.cpp=.gcda) $(SRCS:.cpp=.gcno)

CC		=	g++

CXXFLAGS	=	-W -Wall -Wextra

LDFLAGS		=		\

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_COV)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CXXFLAGS	+=	-g
debug: re