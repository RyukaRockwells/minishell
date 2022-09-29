# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 12:20:40 by nchow-yu          #+#    #+#              #
#    Updated: 2022/09/29 16:52:49 by nchow-yu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c srcs/error.c srcs/deco.c srcs/ft_loop.c srcs/exit.c \
			srcs/ft_init.c srcs/signal.c srcs/parsing/lexer/lexer_utils.c srcs/parsing/lexer/lexer.c \
			srcs/parsing/token/token.c srcs/parsing/lexer/lexer_check.c srcs/parsing/token/token_list.c \
			srcs/parsing/parser/parser.c srcs/parsing/parser/parser_check.c srcs/pre_exec/create_list.c \
			srcs/pre_exec/exe_list.c
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
