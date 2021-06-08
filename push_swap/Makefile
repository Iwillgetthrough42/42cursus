NAME = push_swap

SRCS = libft/ft_atoi.c \
		libft/ft_strlen.c \
		libft/ft_isdigit.c \
		operations/op1.c \
		operations/op2.c \
		operations/op3.c \
		operations/op4.c \
		sort/sort.c \
		sort/sort2.c \
		sort/utils.c \
		sort/utils2.c \
		utils.c \
		sort/frombtoa.c \
		push_swap.c \
		sort/free.c \
		

OBJS = ${SRCS:.c=.o}

RM 	 = rm -f

.c.o:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}: $(OBJS)
	 	 gcc -Wall -Wextra -Werror -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re