# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 15:45:41 by ccamie            #+#    #+#              #
#    Updated: 2021/10/18 15:45:43 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../pipex
HEADER		=	   pipex.h

LIBFT		=	../libft/libft.a
LIBGNL		=	../libgnl/libgnl.a

SRCS		=	foo.c		\
				get_file.c	\
				main.c		\
				parser.c	\
				pipex.c		\
				terminate.c	\

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

OBJS		=	$(SRCS:.c=.o)
OBJ			=	../obj/

.PHONY		:	all clean fclean re

all			:	$(OBJ) $(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(OBJS) $(LIBFT) $(LIBGNL) -o $(NAME)

$(OBJ)%.o	:	%.c $(HEADER) $(LIBFT) $(LIBGNL) | $(OBJ)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)		:
				mkdir $(OBJ)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)
				
re			:	fclean all
