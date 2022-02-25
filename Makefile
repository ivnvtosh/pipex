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

.PHONY		:	all clean fclean re bonus rebonus libft libgnl

all			:	obj libft libgnl
				make -C src all

bonus		:	obj libft libgnl
				make -C src_bonus all

obj			:
				mkdir obj

libft		:
				make -C libft bonus

libgnl		:
				make -C libgnl

clean		:
				make -C src clean
#				make -C src_bonus clean
				make -C libft clean
				make -C libgnl clean

fclean		:
				make -C src fclean
#				make -C src_bonus fclean
				make -C libft fclean
				make -C libgnl fclean
				
re			:	fclean all

rebonus		:	fclean bonus
