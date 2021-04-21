NAME	= libasm.a

SRCS	= ft_read.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s \
		ft_strlen.s \
		ft_write.s

SRCS_B	= ft_atoi_base.s \
		ft_list_push_front.s \
		ft_list_size.s \
		ft_list_sort.s \
		ft_list_remove_if.s

OBJS_B	= $(SRCS_B:.s=.o)

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

clean_b:
			$(RM) $(OBJS_B)

fclean:		clean clean_b
			$(RM) $(NAME) hello.txt empty.txt

re:			fclean all

bonus:		$(OBJS) $(OBJS_B)
			ar rc $(NAME) $(OBJS) $(OBJS_B)

re_b:		fclean bonus

test:		re_b
			gcc -Wall -Wextra -Werror -o test main.c $(NAME) -g -fsanitize=address && ./test
