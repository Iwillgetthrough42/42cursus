NAME = philo_one

SRCS = 	main.c \
		philo.c \
		tools.c \
		
OBJS = ${SRCS:.c=.o}

RM 	 = rm -f

.c.o:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: $(OBJS)
	 	 gcc  -Wall -Wextra -Werror -o ${NAME} ${OBJS}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re