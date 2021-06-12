NAME1 = client

NAME2 = server

SRCS = libft/ft_itoa.c \
 			 libft/ft_atoi.c \
			 libft/ft_strlen.c \

OBJS = ${SRCS:.c=.o}

RM 	 = rm -f

.c.o:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

all:  ${NAME1} ${NAME2}

${NAME1}: $(OBJS)
	 	 gcc -Wall -Wextra -Werror -o ${NAME1} client.c ${OBJS}

${NAME2}: $(OBJS)
		 	gcc -Wall -Wextra -Werror -o ${NAME2} server.c ${OBJS}

clean:
	rm -f $(OBJS)
	rm -f client.o
	rm -f server.o

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re:	fclean all

.PHONY: all clean fclean re
