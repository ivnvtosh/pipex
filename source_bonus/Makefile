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

NAME			=	../pipex

HEADER			=	../include/pipex.h

CFLAGS			=	-Wall -Wextra -Werror

SOURCE			=	ft_here_doc.c	\
					child_name.c	\
					child.c			\
					utils1.c		\
					utils2.c		\
					utils3.c		\
					gnl_bonus.c		\
					gnlu_bonus.c	\
					main_bonus.c	\

OBJECT			=	$(addprefix ../object/, $(SOURCE:.c=.o))

.PHONY			:	all clean fclean re

all				:	$(NAME)

$(NAME)			:	$(OBJECT)
					$(CC) $(OBJECT) -o $(NAME)

../object/%.o	:	../source/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

../object/%.o	:	%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

clean			:
					$(RM) $(OBJECT)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all
