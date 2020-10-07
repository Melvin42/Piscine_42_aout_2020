SRCS	= ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

AR		= ar rc

GCC		= gcc

RM		= rm -rf

INCLUDE = -I ./includes/

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${GCC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS} 
			${AR} ${NAME} ${OBJS}
			
all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
