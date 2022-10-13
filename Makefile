# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicole <nicole@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 12:20:40 by nchow-yu          #+#    #+#              #
#    Updated: 2022/10/13 19:08:37 by nicole           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c srcs/error.c srcs/deco.c srcs/ft_loop.c srcs/exit.c \
			srcs/ft_init.c srcs/signal.c ${TOKEN} ${PARSER} ${EXEC} ${PRE_EXEC} \
			${LEXER} ${FREE} ${SHOW} ${HEREDOC} ${EXPAND} ${UTILS} ${GNL}
SHOW	=	srcs/show/show.c
TOKEN	=	srcs/parsing/token/token.c srcs/parsing/token/token_list.c
PARSER	=	srcs/parsing/parser/parser.c srcs/parsing/parser/parser_check.c
LEXER	=	srcs/parsing/lexer/lexer.c srcs/parsing/lexer/lexer_utils.c srcs/parsing/lexer/lexer_check.c
PRE_EXEC=	srcs/pre_exec/create_list.c srcs/pre_exec/exe_list.c srcs/pre_exec/check_exe.c \
			srcs/pre_exec/add_exe.c
FREE	=	srcs/free/all_free.c srcs/free/all_free2.c
EXEC	=	srcs/exec/exec.c
HEREDOC	=	srcs/parsing/heredoc/heredoc.c srcs/parsing/heredoc/heredoc_utils.c \
			srcs/parsing/heredoc/heredoc_utils2.c
EXPAND	=	srcs/expand/expand.c
UTILS	=	srcs/utils/utils.c
GNL		=	srcs/get_next_line/get_next_line_bonus.c srcs/get_next_line/get_next_line_utils_bonus.c

LIBFT	=	srcs/libft/libft.a
OBJS	=	${SRCS:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra #-g3 -fsanitize=address
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

#valgrind -s --suppressions=ignoreleak --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./minishell
