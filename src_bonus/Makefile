NAME		=	../pipex
HEADER		=	   pipex_bonus.h

LIBFT		=	../libft/libft.a
LIBGNL		=	../libgnl/libgnl.a

SRCS		=	all_bonus.c			\
				main_bonus.c		\
				one_bonus.c			\
				parser_bonus.c		\
				pipex_bonus.c		\
				terminate_bonus.c	\
				two_bonus.c			\
				utils_bonus.c		\

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
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
