# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melperri <melperri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 19:05:36 by melperri          #+#    #+#              #
#    Updated: 2020/08/24 22:35:26 by melperri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= calc.c funct.c maindoop.c

OBJS 	= ${SRCS:.c=.o}

NAME 	= do-op

CFLAGS 	= -Wall -Wextra -Werror

CC		= @gcc

RM		= @rm -rf

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS}
			 ${CC} -o ${NAME} ${OBJS}

all :		${NAME}

clean :
			 ${RM} ${OBJS}

fclean :	clean
			 ${RM} ${NAME}

re :		fclean all

.SILENT:	clean fclean .c.o all re ${NAME}

.PHONY: 	all clean fclean re
