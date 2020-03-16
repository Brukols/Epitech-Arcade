##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Arcade
##

NAME	=	lib_arcade_ncurses.so

SRCS	=	src/Graphical/Graphical.cpp	\
			src/Graphical/display/GraphicalDisplay.cpp	\
			src/SceneMenu/SceneMenu.cpp	\
			src/SceneMenu/init/SceneMenuInit.cpp	\
			src/SceneMenu/init/SceneMenuSetter.cpp	\
			src/SceneMenu/init/SceneMenuInitRects.cpp	\
			src/SceneMenu/init/SceneMenuInitTexts.cpp	\
			src/SceneMenu/init/SceneMenuInitButtons.cpp	\
			src/SceneMenu/init/SceneMenuInitListGames.cpp	\
			src/SceneMenu/init/SceneMenuInitListLibraries.cpp	\
			src/SceneMenu/display/SceneMenuDisplay.cpp	\
			src/SceneMenu/event/SceneMenuEvent.cpp		\
			src/SceneMenu/event/SceneMenuEventButtons.cpp		\
			src/SceneGame/SceneGame.cpp	\
			src/SceneGame/init/SceneGameInit.cpp	\
			src/SceneGame/init/SceneGameSetters.cpp	\
			src/SceneGame/init/SceneGameInitButtons.cpp	\
			src/SceneGame/init/SceneGameInitRects.cpp	\
			src/SceneGame/init/SceneGameInitTexts.cpp	\
			src/SceneGame/init/SceneGameInitMap.cpp	\
			src/SceneGame/display/SceneGameDisplay.cpp	\
			src/SceneGame/event/SceneGameEvent.cpp	\
			src/SceneGame/event/SceneGameEventButtons.cpp	\
			src/Rectangle/Rectangle.cpp		\
			src/Utility/Utility.cpp	\
			src/Text/Text.cpp		\
			src/Button/Button.cpp		\

OBJS	=	$(SRCS:.cpp=.o)

OBJS_TEST	=	$(SRCS:.cpp=.gcno) $(SRCS:.cpp=.gcda)

CXXFLAGS	=	-I./include -I../../include -W -Wall -Wextra -std=c++17 -fPIC

LDFLAGS		=	-lncurses

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