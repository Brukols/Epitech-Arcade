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

OBJS	=	$(SRCS:.cpp=.o)

OBJS_COV	=	$(SRCS:.cpp=.gcno) $(SRCS:.cpp=.gcda)

CC	=		g++

CXXFLAGS	=	-I./include -I../include -W -Wall -Wextra -std=c++17

LDFLAGS		=	-ldl	\

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