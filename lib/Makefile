##
## EPITECH PROJECT, 2020
## Arcal
## File description:
## Makefile
##

NAME_SFML	=	lib_arcade_sfml.so

SRCS_SFML	=	src/sfml/SFMLGraphical.cpp	\
				src/sfml/init/SFMLGraphicalInitButtons.cpp	\
				src/sfml/init/SFMLGraphicalInitButtonsMenu.cpp	\
				src/sfml/init/SFMLGraphicalInitText.cpp	\
				src/sfml/init/SFMLGraphicalInitTextMenu.cpp	\
				src/sfml/event/SFMLGraphicalEvent.cpp	\
				src/sfml/display/SFMLGraphicalDisplay.cpp	\
				src/sfml/display/SFMLGraphicalDisplayEndGame.cpp	\
				src/sfml/display/SFMLGraphicalDisplayGame.cpp	\
				src/sfml/display/SFMLGraphicalDisplayMenu.cpp	\
				src/sfml/button/SFMLButton.cpp	\
				src/sfml/text/SFMLText.cpp	\
				src/sfml/music/SFMLGraphicalMusic.cpp	\

OBJS	=	$(SRCS_SFML:.cpp=.o)

OBJS_TEST	=	$(SRCS_SFML:.cpp=.gcno) $(SRCS_SFML:.cpp=.gcda)

CXXFLAGS	=	-I./include -I../include -W -Wall -Wextra -std=c++17 -fPIC

SFML_FLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

LDFLAGS		=	\

CC	=	g++

RM	=	rm -f

all: $(NAME_SFML)

$(NAME_SFML): $(OBJS)
	$(CC) -shared -o $(NAME_SFML) $(OBJS) $(SFML_FLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_TEST)

fclean: clean
	$(RM) $(NAME_SFML)

re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY:	all clean fclean re debug