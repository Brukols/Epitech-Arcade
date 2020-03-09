##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Arcade
##

NAME	=	lib_arcade_sfml.so

SRCS	=	src/Graphical.cpp	\
			src/init/GraphicalInitButtons.cpp	\
			src/init/GraphicalInitButtonsMenu.cpp	\
			src/init/GraphicalInitText.cpp	\
			src/init/GraphicalInitTextMenu.cpp	\
			src/event/GraphicalEvent.cpp	\
			src/display/GraphicalDisplay.cpp	\
			src/display/GraphicalDisplayEndGame.cpp	\
			src/display/GraphicalDisplayGame.cpp	\
			src/display/GraphicalDisplayMenu.cpp	\
			src/button/Button.cpp	\
			src/text/Text.cpp	\
			src/music/GraphicalMusic.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

OBJS_TEST	=	$(SRCS:.cpp=.gcno) $(SRCS:.cpp=.gcda)

CXXFLAGS	=	-I./include -I../../include -W -Wall -Wextra -std=c++17 -fPIC

LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system

CC	=	g++

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -shared -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_TEST)

fclean: clean
	$(RM) $(NAME_SFML)

re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY:	all clean fclean re debug