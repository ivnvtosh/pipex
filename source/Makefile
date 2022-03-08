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

SOURCE			=	child_name.c	\
					child.c			\
					main.c			\
					utils1.c		\
					utils2.c		\
					utils3.c		\

OBJECT			=	$(addprefix ../object/, $(SOURCE:.c=.o))

.PHONY			:	all clean fclean re

all				:	$(NAME)

$(NAME)			:	$(OBJECT)
					$(CC) $(OBJECT) -o $(NAME)

../object/%.o	:	%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

clean			:
					$(RM) $(OBJECT)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all
