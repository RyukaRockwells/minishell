# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 12:20:40 by nchow-yu          #+#    #+#              #
#    Updated: 2022/07/17 21:44:15 by nchow-yu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c
LIBFT	=	libft/libft.a
OBJS	=	${SRCS:.c=.o}
CC	=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g3
NAME	=	minishell

%.o:	%.c
	${CC} -g3 -c $< -o ${<:.c=.o}

all:	${OBJS} ${NAME}

${NAME}:	${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -lreadline -L.local/lib -o ${NAME}

${LIBFT}:
	make -C libft

clean:
	rm -rf ${OBJS}
	make clean -C libft

fclean:    clean
	rm -rf ${NAME}
	make fclean -C libft

re:	fclean all

.PHONY:	all clean fclean re
