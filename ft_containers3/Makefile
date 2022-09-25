NAME1 = ft_containers
NAME2 = std_containers
NAME = intramain

SRCS = 	main2.cpp \

GR=\033[0;32m
RED=\033[0;31m
RES=\033[0;0m
OBJS = ${SRCS:.cpp=.o}
.cpp.o:
		@c++ -Wall -Wextra -Werror -std=c++98 -c main2.cpp -o stdvers.o -DSTDSTL
		@c++ -Wall -Wextra -Werror -std=c++98 -c main2.cpp -o ftvers.o
		@c++ -Wall -Wextra -Werror -std=c++98 -c main.cpp -o main.o

all: ${NAME1} ${NAME2} ${NAME}

${NAME1}: 	$(OBJS)
			@c++ -Wall -Wextra -Werror -std=c++98 -o ${NAME1} ftvers.o
			@echo "$(GR) welcome to ft_containers $(RES)"

${NAME2}: 	$(OBJS)
			@c++ -Wall -Wextra -Werror  -std=c++98 -o ${NAME2} stdvers.o

${NAME}:	$(OBJS)
			@c++ -Wall -Wextra -Werror -std=c++98 -o ${NAME} main.o

clean:
			@rm -f $(OBJS)
			@rm -f main.o
			@rm -f stdvers.o
			@rm -f ftvers.o

fclean:		clean
			@rm -f ${NAME1}
			@rm -f ${NAME2}
			@rm -f ${NAME}
			@echo "$(RED) GOODBYE $(RES)"

re:			fclean all

.PHONY: all clean fclean re