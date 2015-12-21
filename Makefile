##
## Makefile for Makefile in /home/rinaz_a/rendu/PSU_2015_my_select
## 
## Made by selim rinaz
## Login   <rinaz_a@epitech.net>
## 
## Started on  Fri Dec  4 16:34:29 2015 selim rinaz
## Last update Mon Dec 21 22:13:43 2015 
##

CC	= gcc -g

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
#CFLAGS	+=-ansi -pedantic
#CFLAGS	+= -I.

NAME	= bsq

SRCS	= my_essentials.c \
	  move_to_2d.c \
	  goto_int_2d.c \
	  bsq.c

OBJS	= $(SRCS:.c=.o)


all: 	$(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
