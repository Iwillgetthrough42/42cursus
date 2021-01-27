# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arastepa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 12:43:16 by arastepa          #+#    #+#              #
#    Updated: 2021/01/27 14:46:09 by arastepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memset.c	\
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_strlcat.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

OBJS	= 	${SRCS:.c=.o}

RM		=	rm -f

LIBC	= ar -rcs

CFLAGS	=	-Wall -Wextra -Werror

INCS	= .

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME):	${OBJS}
			${LIBC}  $(NAME) $(OBJS)

all:		$(NAME)

clean:		
			$(RM) -f $(OBJS)

fclean:		clean
			$(RM)  $(NAME)

re:			fclean all

.PHONY:		all clean fclean re .c.o
