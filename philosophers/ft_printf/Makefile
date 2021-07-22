LIBNAME = libftprintf.a

SRCS = ft_printf.c \
		printfunctions.c \
		printspace.c \
		to_hex.c \
		checker.c \
		ft_utoa.c \
		libft/ft_strlen.c \
		libft/ft_strdup.c \
		libft/ft_itoa.c \
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_memcpy.c \

OBJS = $(SRCS:.c=.o)

RM 	 = rm -f

.c.o:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

$(LIBNAME): $(OBJS)
	 ar rcs $(LIBNAME) $(OBJS)

all: $(LIBNAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re