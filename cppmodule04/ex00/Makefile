NAME = animal

WRONG = wrong

SRCS = Animal.cpp \
       Cat.cpp \
       Dog.cpp \
       main.cpp \

WRONGSRCS = WrongAnimal.cpp \
			WrongCat.cpp \
			wrongmain.cpp \

OBJS = ${SRCS:.cpp=.o}

WRONGOBJS = ${WRONGSRCS:.cpp=.o}

.cpp.o:
		c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $(<:.cpp=.o)

all:${NAME}

${NAME}:	${OBJS}
		c++ -Wall -Wextra -Werror -std=c++98 -o ${NAME} ${OBJS}

${WRONG}:	${WRONGOBJS}
		c++ -Wall -Wextra -Werror -std=c++98 -o ${WRONG} ${WRONGOBJS}

clean:
	rm -f ${OBJS}
	rm -f ${WRONGOBJS}
fclean:	clean
	rm -f ${NAME}
	rm -f ${WRONG}

re: fclean all

.PHONY:
	all clean fclean re
