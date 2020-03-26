##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME	=	lib_arcade_sdl.so

SRCS	=	src/Graphical/Graphical.cpp		\
			src/SceneMenu/SceneMenu.cpp		\
			src/SceneMenu/init/SceneMenuInit.cpp	\
			src/SceneMenu/init/SceneMenuInitRects.cpp	\
			src/SceneMenu/init/SceneMenuInitTexts.cpp	\
			src/SceneMenu/init/SceneMenuInitButtons.cpp	\
			src/SceneMenu/event/SceneMenuEvent.cpp	\
			src/SceneMenu/display/SceneMenuDisplay.cpp	\
			src/SceneGame/SceneGame.cpp	\
			src/SceneGame/init/SceneGameInit.cpp	\
			src/SceneGame/init/SceneGameInitRects.cpp	\
			src/SceneGame/init/SceneGameInitButtons.cpp	\
			src/SceneGame/init/SceneGameInitTexts.cpp	\
			src/SceneGame/event/SceneGameEvent.cpp	\
			src/SceneGame/display/SceneGameDisplay.cpp	\
			src/SceneEndGame/SceneEndGame.cpp	\
			src/SceneEndGame/init/SceneEndGameInit.cpp	\
			src/SceneEndGame/event/SceneEndGameEvent.cpp	\
			src/SceneEndGame/display/SceneEndGameDisplay.cpp	\
			src/SceneScores/SceneScores.cpp		\
			src/Utility/Utility.cpp	\
			src/Rectangle/Rectangle.cpp		\
			src/Text/Text.cpp	\
			src/ButtonRect/ButtonRect.cpp		\
			src/ListLibraries/ListLibraries.cpp		\
			src/ListLibraries/ListLibrariesInit.cpp		\
			src/ListScores/ListScores.cpp	\
			src/Input/Input.cpp		\
			src/ScenePause/ScenePause.cpp	\
			src/SceneHowToPlay/SceneHowToPlay.cpp	\
			src/Errors/Errors.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

OBJS_TEST	=	$(SRCS:.cpp=.gcno) $(SRCS:.cpp=.gcda)

CXXFLAGS	=	-I./include -I../../include -W -Wall -Wextra -std=c++17 -fPIC

LDFLAGS		=	-lSDL2 -lSDL2_ttf

CC	=	g++

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -shared -o $(NAME) $(OBJS) $(LDFLAGS)
	mv $(NAME) ../

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_TEST)

fclean: clean
	$(RM) ../$(NAME)

re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY:	all clean fclean re debug