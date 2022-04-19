NAME = Bureaucrat

SRCS = 	Form.cpp \
		Bureaucrat.cpp \
       	main.cpp \

OBJS = ${SRCS:.cpp=.o}

all:${NAME}

.cpp.o:
		c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $(<:.cpp=.o)

${NAME}:	${OBJS}
		c++ -Wall -Wextra -Werror -std=c++98 -o ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}
fclean:	clean
	rm -f ${NAME}

re: fclean all

.PHONY:
	all clean fclean re
