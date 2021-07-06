NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = libft.h
INCLUDE = -I include
PARSER = parser
LIVE_PHILO = live_philo
AUXILIARY_FUNCTIONS = auxiliary_functions
SRCS =	${PARSER}/parser.c \
		${LIVE_PHILO}/live_philo.c \
		${AUXILIARY_FUNCTIONS}/auxiliary_functions.c \
		${AUXILIARY_FUNCTIONS}/ft_atoi.c \
		${AUXILIARY_FUNCTIONS}/auxiliary_functions_utils.c \
		philo.c

OBJS =	${SRCS:.c=.o}

%.o: %.c
	$(CC) -o $(FLAGS) ${INCLUDE} -c $<  -o $(<:.c=.o)

all:		${NAME}

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS} ${INCLUDE}

test:
	gcc -g ${FLAGS} ${INCLUDE} ${PARSER}/parser.c ${LIVE_PHILO}/live_philo.c ${AUXILIARY_FUNCTIONS}/auxiliary_functions.c ${AUXILIARY_FUNCTIONS}/ft_atoi.c ${AUXILIARY_FUNCTIONS}/auxiliary_functions_utils.c philo.c

clean:
		rm -f $(OBJS)

fclean:	
			rm -f $(OBJS) $(NAME)

re:			fclean all

.PHONY:
			all clean fclean re