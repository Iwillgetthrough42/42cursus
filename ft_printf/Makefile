NAME = libftprintf.a

SRCS = ft_printf.c \
		printfunctions.c \
		printspace.c \
		to_hex.c \
		checker.c \
		libft/ft_strlen.c \
		libft/ft_strdup.c \
		libft/ft_itoa.c \
		libft/ft_substr.c \

OBJS = $(SRCS:.c=.o)

RM 	 = rm -f

.c.o:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

all: $(OBJS)
	 ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re