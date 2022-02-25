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

SRCS		=	foo.c			\
				get_bins.c		\
				get_commands.c	\
				get_paths.c		\
				get_file.c		\
				main.c			\
				parser.c		\
				pipex.c			\
				process_child.c	\
				process_parent.c\
				terminate.c		\

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -f

OBJS		=	$(addprefix ../obj/, $(SRCS:.c=.o))

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(OBJS) $(LIBFT) $(LIBGNL) -o $(NAME)

../obj/%.o	:	%.c $(HEADER) $(LIBFT) $(LIBGNL)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)
				
re			:	fclean all
