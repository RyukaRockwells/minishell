# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchow-yu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 12:20:40 by nchow-yu          #+#    #+#              #
#    Updated: 2022/07/13 12:30:10 by nchow-yu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c
OBJS	=	${SRCS:.c=.o}
CC	=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g3
NAME	=	minishell

%.o:	%.c
	${CC} -g3 -c $< -o ${<:.c=.o}

all:	${OBJS} ${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -lreadline -L.local/lib -o ${NAME}


clean:
	rm -rf ${OBJS}

fclean:    clean
	rm -rf ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
