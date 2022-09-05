# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 12:20:40 by nchow-yu          #+#    #+#              #
#    Updated: 2022/09/05 13:33:13 by nchow-yu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c srcs/ft_error.c srcs/deco.c srcs/ft_loop.c srcs/exit.c \
			srcs/ft_init.c srcs/signal.c srcs/lexer/lexer_utils.c srcs/lexer/lexer.c \
			srcs/token/token.c srcs/lexer/lexer_check.c srcs/token/token_list.c \
			srcs/parser/parser.c srcs/parser/parser_check.c
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
