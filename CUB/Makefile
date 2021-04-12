SRCS = get_next_line/get_next_line.c \
		libft/ft_memcpy.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_strlen.c \
		libft/ft_substr.c \
		libft/ft_atoi.c \
		libft/ft_strjoin.c \
		libft/ft_memcmp.c \
		libft/ft_memset.c \
		libft/ft_bzero.c \
		utils1.c \
		utils2.c \
		to_hex.c \
		readmap.c \
		fromfile.c \
		init.c \
		init2.c \
		calc.c \
		utilstext.c \
		error.c \
		ft_isspace.c \
		checkmapins.c \
		keys.c \
		near.c \
		cub.c \
		sprites.c \
		sprtools.c \
		screenshot.c \
	

OBJS = $(SRCS:.c=.o)

RM 		= rm -f
LIBC	= -Lmlx -lmlx -framework OpenGL -framework Appkit -lm
MLX		= libmlx.dylib

NAME	= cub3d

all:  $(MLX) $(OBJS)
	 gcc -Wall -Wextra -Werror -o ${NAME} ${OBJS} ${LIBC} 

$(MLX):
		@$(MAKE) -C mlx 
		@mv mlx/$(MLX) .

clean:
	@$(MAKE) -C mlx clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(MLX)

re:	fclean all

.PHONY: all clean fclean re