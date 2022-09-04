# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 12:20:40 by nchow-yu          #+#    #+#              #
#    Updated: 2022/09/04 17:33:29 by nchow-yu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c srcs/ft_error.c srcs/deco.c srcs/ft_loop.c srcs/exit.c \
			srcs/ft_init.c srcs/signal.c srcs/lexer_utils.c srcs/lexer.c \
			srcs/token.c srcs/lexer_check.c srcs/token_list.c srcs/parser.c \
			srcs/parser_check.c
LIBFT	=	srcs/libft/libft.a
OBJS	=	${SRCS:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g3 -fsanitize=address
NAME	=	minishell

%.o:	%.c
	@${CC} -g3 -c $< -o ${<:.c=.o}

all:	${OBJS} ${NAME}

${NAME}:	${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -lreadline -L.local/lib -o ${NAME}

${LIBFT}:
	@make -C srcs/libft

clean:
	@rm -rf ${OBJS}
	@make clean -C srcs/libft

fclean:    clean
	@rm -rf ${NAME}
	@make fclean -C srcs/libft

re:	fclean all

.PHONY:	all clean fclean re
