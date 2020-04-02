##
## EPITECH PROJECT, 2020
## Core
## File description:
## Makefile
##

NAME	=	arcade

SRCS	=	src/main.cpp	\
			src/Errors.cpp	\
			src/Core.cpp 	\
			src/CoreSetGame.cpp	\
			src/CoreSetGraphical.cpp	\
			src/Folder.cpp	\
			src/File.cpp	\
			src/Score.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

OBJS_COV	=	$(SRCS:.cpp=.gcno) $(SRCS:.cpp=.gcda)

CC	=		g++

CXXFLAGS	=	-I./include -I../include -W -Wall -Wextra -std=c++17

LDFLAGS		=	-ldl -lstdc++fs	\

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_COV)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CXXFLAGS	+=	-g
debug: re