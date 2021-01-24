# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arastepa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 12:43:16 by arastepa          #+#    #+#              #
#    Updated: 2021/01/23 16:37:53 by arastepa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = memset.c	\
	   bzero.c

OBJS	= 	${SRCS:.c=.o}

NAME	=	libft.a

CC		=	cc
RM		= 	rm -f

CFLAGS	=	-Wall -Wextra -Werror

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM}  ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
