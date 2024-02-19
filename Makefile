CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = output.c main.c input.c ft_printf.c sort.c operations_0.c operations_1.c operations_2.c sort_1.c sort_2.c
BSRCS = checker.c output.c input.c ft_printf.c sort.c operations_0.c operations_1.c operations_2.c sort_1.c sort_2.c
NAME = push_swap
BONUS = checker
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
LIB = libft/libft.a
all: $(NAME)

bonus: $(BONUS)

$(BONUS): $(BOBJS)
	make -C libft
	CC $(CFLAGS) $^ $(LIB) -o $@

$(NAME): $(OBJS)
	make -C libft
	CC $(CFLAGS) $^ $(LIB) -o $@

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus