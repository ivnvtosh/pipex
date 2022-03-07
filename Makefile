# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 20:01:32 by ccamie            #+#    #+#              #
#    Updated: 2022/03/07 20:07:26 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

HEADER		=	include/pipex.h
HEADER_B	=	include/pipex.h

CFLAGS		=	-Wall -Wextra -Werror

SOURCE		=	child.c		\
				main.c		\
				utils1.c	\
				utils2.c	\
				utils3.c	\

SOURCE_B	=	child.c		\
				main_bonus.c\
				utils1.c	\
				utils2.c	\
				utils3.c	\

OBJECT		=	$(addprefix object/, $(SOURCE:.c=.o))
OBJECT_B	=	$(addprefix object/, $(SOURCE_B:.c=.o))

.PHONY		:	all clean fclean re

all			:	object $(NAME)

$(NAME)		:	$(OBJECT)
				$(CC) $(OBJECT) -o $(NAME)

object/%.o	:	source/%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

object		:
				mkdir object

clean		:
				$(RM) $(OBJECT)
				rmdir object

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
