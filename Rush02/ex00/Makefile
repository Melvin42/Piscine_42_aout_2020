SRCS 	= basic.c check_the_num.c split_string2.c string_check2.c num_to_trios.c print_trio.c split_dict.c read_dict.c extract_def.c main.c

OBJS 	= ${SRCS:.c=.o}

NAME 	= rush-02

CFLAGS 	= -Wall -Wextra #-Werror

CC		= gcc

RM		= rm -rf

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS} 
			${CC} -o ${NAME} ${OBJS}  

all :		${NAME}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}

re :		fclean all

.PHONY: 	all clean fclean re
