NAME	= libasm.a

SRCS	= ft_read.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s \
		ft_strlen.s \
		ft_write.s

OBJS	= $(SRCS:.s=.o)

CC		= nasm

CFLAGS 	= -f elf64

RM		= rm -rf

.s.o:
			$(CC) $(CFLAGS) $< -o $(<:.s=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) test*

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

test:		re $(OBJS)
			gcc -Wall -Wextra -Werror -o test main.c $(NAME) -fsanitize=address -g && ./test
