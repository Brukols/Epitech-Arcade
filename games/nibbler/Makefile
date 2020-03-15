##
## EPITECH PROJECT, 2020
## Arcade - Nibbler
## File description:
## Makefile
##

NAME_NIBBLER	=	lib_arcade_nibbler.so

SRCS_NIBBLER	=	src/Nibbler.cpp	\
					src/InitNibbler.cpp	\

OBJS	=	$(SRCS_NIBBLER:.cpp=.o)

OBJS_TEST	=	$(SRCS_NIBBLER:.cpp=.gcno) $(SRCS_NIBBLER:.cpp=.gcda)

CXXFLAGS	=	-I./include -I../../include -W -Wall -Wextra -std=c++17 -fPIC

LDFLAGS		=	\

CC	=	g++

RM	=	rm -f

all: $(NAME_NIBBLER)

$(NAME_NIBBLER): $(OBJS)
	$(CC) -shared -o $(NAME_NIBBLER) $(OBJS)
	mv $(NAME_NIBBLER) ../

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_TEST)

fclean: clean
	$(RM) ../$(NAME_NIBBLER)

re: fclean all

debug: CXXFLAGS += -g
debug: re

.PHONY:	all clean fclean re debug