##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Arcade
##

NAME	=	lib_arcade_sfml.so

SRCS	=	src/Graphical.cpp	\
			src/event/GraphicalEvent.cpp	\
			src/display/GraphicalDisplay.cpp	\
			src/button/Button.cpp	\
			src/text/Text.cpp	\
			src/music/GraphicalMusic.cpp	\
			src/SceneMenu/SceneMenu.cpp	\
			src/SceneMenu/init/SceneMenuInit.cpp	\
			src/SceneMenu/init/SceneMenuInitButtons.cpp	\
			src/SceneMenu/init/SceneMenuInitTexts.cpp	\
			src/SceneMenu/init/SceneMenuSetter.cpp	\
			src/SceneMenu/init/SceneMenuInitListGames.cpp	\
			src/SceneMenu/init/SceneMenuInitListLibraries.cpp	\
			src/SceneMenu/display/SceneMenuDisplay.cpp	\
			src/SceneMenu/event/SceneMenuEvent.cpp		\
			src/Utility/Utility.cpp	\

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