NAME = philo_one

SRCS = 	main.c \
		philo.c \

LIBFT = ../libft/libft.a

FT_PRINTF = ../ft_printf/libftprintf.a
		
OBJS = ${SRCS:.c=.o}

RM 	 = rm -f

.c.o:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

all: ${LIBFT} ${NAME}

${LIBFT}:
		@make -C ../libft/ --silent
		@echo "$(GREEN) libft.a	created! $(RESET)"

${FT_PRINTF}:
		@make -C ../ft_printf/ --silent
		@echo "$(GREEN) libftprintf.a	created! $(RESET)"


${NAME}: $(FT_PRINTF) $(OBJS)
	 	 gcc $(FT_PRINTF) $(LIBFT)  -Wall -Wextra -Werror -o ${NAME} ${OBJS}

clean:
	@make -C ../libft clean;
	@make -C ../ft_printf clean;
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)

re:	fclean all

.PHONY: all clean fclean re