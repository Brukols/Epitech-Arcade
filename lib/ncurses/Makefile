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
			src/SceneMenu/init/SceneMenuInitTexts.cpp	\
			src/SceneMenu/init/SceneMenuInitButtons.cpp	\
			src/SceneMenu/init/SceneMenuInitInputs.cpp	\
			src/SceneMenu/display/SceneMenuDisplay.cpp	\
			src/SceneMenu/event/SceneMenuEvent.cpp		\
			src/SceneGame/SceneGame.cpp	\
			src/SceneGame/init/SceneGameInit.cpp	\
			src/SceneGame/init/SceneGameSetters.cpp	\
			src/SceneGame/init/SceneGameInitButtons.cpp	\
			src/SceneGame/init/SceneGameInitTexts.cpp	\
			src/SceneGame/init/SceneGameInitMap.cpp	\
			src/SceneGame/init/SceneGameInitTextHowToPlay.cpp	\
			src/SceneGame/init/SceneGameInitTextStats.cpp	\
			src/SceneGame/display/SceneGameDisplay.cpp	\
			src/SceneGame/event/SceneGameEvent.cpp	\
			src/SceneEndGame/SceneEndGame.cpp	\
			src/SceneEndGame/init/SceneEndGameInit.cpp	\
			src/SceneEndGame/init/SceneEndGameInitButtons.cpp	\
			src/SceneEndGame/event/SceneEndGameEvent.cpp	\
			src/SceneEndGame/display/SceneEndGameDisplay.cpp	\
			src/SceneError/SceneError.cpp	\
			src/SceneError/display/SceneErrorDisplay.cpp	\
			src/SceneError/init/SceneErrorInit.cpp	\
			src/SceneError/event/SceneErrorEvent.cpp	\
			src/SceneScores/SceneScores.cpp	\
			src/SceneScores/init/SceneScoresInit.cpp	\
			src/SceneScores/event/SceneScoresEvent.cpp	\
			src/SceneScores/display/SceneScoresDisplay.cpp	\
			src/Rectangle/Rectangle.cpp		\
			src/Utility/Utility.cpp	\
			src/Text/Text.cpp		\
			src/Button/Button.cpp		\
			src/NcursesError/NcursesError.cpp	\
			src/Input/Input.cpp		\
			src/List/List.cpp	\
			src/List/ListEvent.cpp	\
			src/List/ListInitButtons.cpp	\
			src/ListScores/ListScores.cpp	\
			src/ListScores/ListScoresEvent.cpp	\
			src/ListScores/ListScoresInit.cpp	\
			src/ScenePause/ScenePause.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

OBJS_TEST	=	$(SRCS:.cpp=.gcno) $(SRCS:.cpp=.gcda)

CXXFLAGS	=	-I./include -I../../include -W -Wall -Wextra -std=c++17 -fPIC

LDFLAGS		=	-lncurses

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