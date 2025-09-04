CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes
SRCS = srcs/main.c srcs/get_op_index.c srcs/ft_putnbr.c srcs/ft_atoi.c srcs/do_op.c
OBJS = ${SRCS:.c=.o}
NAME = do-op
RM = rm -f

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all