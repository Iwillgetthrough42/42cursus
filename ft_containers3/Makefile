NAME = ft_containers

SRCS = 	main.cpp \

OBJS = ${SRCS:.cpp=.o}

GR=\033[0;32m
RED=\033[0;31m
RES=\033[0;0m

.cpp.o:
		@c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@

all: ${NAME}

${NAME}: 	$(OBJS)
			@c++ -Wall -Wextra -Werror -std=c++98 -o ${NAME} ${OBJS}
			@echo "$(GR) welcome to ft_containers $(RES)"

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f ${NAME}
			@echo "$(RED) GOODBYE $(RES)"

re:			fclean all

.PHONY: all clean fclean re