NAME		=	pipex
HEADER		=	include/pipex.h

CFLAGS		=	-Wall -Wextra -Werror

SOURCE		=	child.c		\
				main.c		\
				utils1.c	\
				utils2.c	\
				utils3.c	\

# SOURCE_B	=

OBJECT		=	$(addprefix object/, $(SOURCE:.c=.o))

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
