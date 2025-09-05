CC = cc
CFLAGS =  -Wall -Wextra -Werror -I./includes
SRCS  = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS =  ${SRCS:.c=.o}
NAME = libft.a
RM = rm -f
AR = ar crs

srcs/%.o : srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)


.PHONY: all clean fclean re

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

re: fclean all