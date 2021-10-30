NAME = replace

SRCS = 	main.cpp \

OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: 	$(OBJS)
			clang++ -Wall -Wextra -Werror -o ${NAME} ${OBJS}

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re