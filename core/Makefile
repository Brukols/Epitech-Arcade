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
			src/DLLoader.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

OBJS_COV	=	$(SRCS:.cpp=.gcno) $(SRCS:.cpp=.gcda)

CC	=		g++

CXXFLAGS	=	-I./include -I../include -W -Wall -Wextra

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