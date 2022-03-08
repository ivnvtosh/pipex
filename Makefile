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

.PHONY			:	all clean fclean re bonus rebonus

all				:	object
					make -C source all

bonus			:	object
					make -C source_bonus all

object			:
					mkdir object

clean			:
					make -C source clean
					make -C source_bonus clean
					rmdir object

fclean			:
					make -C source fclean
					make -C source_bonus fclean

re				:	fclean all

rebonus			:	fclean bonus
