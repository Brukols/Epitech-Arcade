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
			src/input/Input.cpp	\
			src/SceneMenu/SceneMenu.cpp	\
			src/SceneMenu/init/SceneMenuInit.cpp	\
			src/SceneMenu/init/SceneMenuInitButtons.cpp	\
			src/SceneMenu/init/SceneMenuInitTexts.cpp	\
			src/SceneMenu/init/SceneMenuSetter.cpp	\
			src/SceneMenu/init/SceneMenuInitListGames.cpp	\
			src/SceneMenu/init/SceneMenuInitListLibraries.cpp	\
			src/SceneMenu/init/SceneMenuInitInput.cpp	\
			src/SceneMenu/init/SceneMenuInitRects.cpp	\
			src/SceneMenu/init/SceneMenuInitImages.cpp	\
			src/SceneMenu/display/SceneMenuDisplay.cpp	\
			src/SceneMenu/event/SceneMenuEvent.cpp		\
			src/SceneMenu/event/SceneMenuEventButtonPlay.cpp		\
			src/SceneMenu/event/SceneMenuEventValidateUsername.cpp		\
			src/SceneGame/SceneGame.cpp	\
			src/SceneGame/init/SceneGameInit.cpp	\
			src/SceneGame/init/SceneGameInitButtons.cpp	\
			src/SceneGame/init/SceneGameInitRects.cpp	\
			src/SceneGame/init/SceneGameSetter.cpp	\
			src/SceneGame/display/SceneGameDisplay.cpp	\
			src/SceneGame/event/SceneGameEvent.cpp	\
			src/SceneGame/event/SceneGameEventButtons.cpp	\
			src/Utility/Utility.cpp	\
			src/image/Image.cpp	\
			src/SFMLErrors/SFMLErrors.cpp	\
			src/ErrorMessage/ErrorMessage.cpp	\

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