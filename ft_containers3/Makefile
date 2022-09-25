NAME1 = ft_containers
NAME2 = std_containers
NAME = intramain

SRCS = 	main2.cpp \

OBJS = ${SRCS:.cpp=.o}

GR=\033[0;32m
RED=\033[0;31m
RES=\033[0;0m

.cpp.o:
		@c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@
		@c++ -Wall -Wextra -Werror -std=c++98 -c main.cpp -o main.o

all: ${NAME1} ${NAME2} ${NAME}

${NAME1}: 	$(OBJS)
			@c++ -Wall -Wextra -Werror -std=c++98 -o ${NAME1} ${OBJS}
			@echo "$(GR) welcome to ft_containers $(RES)"

${NAME2}: 	$(OBJS)
			@c++ -Wall -Wextra -Werror -D STDSTL -std=c++98 -o ${NAME2} ${OBJS}

${NAME}:	$(OBJS)
			@c++ -Wall -Wextra -Werror -std=c++98 -o ${NAME} main.o

clean:
			@rm -f $(OBJS)
			@rm -f main.o

fclean:		clean
			@rm -f ${NAME1}
			@rm -f ${NAME2}
			@rm -f ${NAME}
			@echo "$(RED) GOODBYE $(RES)"

re:			fclean all

.PHONY: all clean fclean re