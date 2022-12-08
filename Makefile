# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicole <nicole@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 12:20:40 by nchow-yu          #+#    #+#              #
#    Updated: 2022/12/08 13:15:44 by nicole           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(addprefix srcs/, main.c error.c ft_loop.c exit.c ft_init.c) \
			${TOKEN} ${PARSER} ${EXEC} ${PRE_EXEC} ${LEXER} ${FREE} ${SHOW} \
			${HEREDOC} ${EXPAND} ${UTILS} ${GNL} ${SIGNAL} ${BUILTIN} ${REDIRECT} \
			${RM_QUOTE}
SHOW	=	srcs/show/show.c
REDIRECT=	$(addprefix srcs/redirect/, redirect.c)
RM_QUOTE=	$(addprefix srcs/rm_quotes/, rm_quotes.c rm_quotes_redirect.c)
SIGNAL	=	$(addprefix srcs/signal/, signal.c signal2.c)
TOKEN	=	$(addprefix srcs/parsing/token/, token.c token_list.c)
PARSER	=	$(addprefix srcs/parsing/parser/, parser.c parser_check.c)
LEXER	=	$(addprefix srcs/parsing/lexer/, lexer.c lexer_utils.c lexer_check.c)
PRE_EXEC=	$(addprefix srcs/pre_exec/, exe_list.c)
FREE	=	$(addprefix srcs/free/, all_free.c all_free2.c)
EXEC	=	$(addprefix srcs/exec/, exe_utils.c exec.c exe_simple_cmd.c \
			exe_several_cmd.c)
HEREDOC	=	$(addprefix srcs/heredoc/, heredoc.c heredoc_utils.c)
EXPAND	=	$(addprefix srcs/expand/, expand.c expand_utils.c)
UTILS	=	$(addprefix srcs/utils/, utils.c deco.c)
GNL		=	$(addprefix srcs/get_next_line/, get_next_line_bonus.c get_next_line_utils_bonus.c)
BUILTIN	=	$(addprefix srcs/builtins/, builtin.c)

LIBFT	=	srcs/libft/libft.a
OBJS	=	${SRCS:.c=.o}
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g3# -fsanitize=address
NAME	=	minishell

%.o:	%.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${OBJS} ${NAME}

${NAME}:	${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -lreadline -L.local/lib -o ${NAME}

${LIBFT}:
	make -C srcs/libft

clean:
	rm -rf ${OBJS}
	make clean -C srcs/libft

fclean:    clean
	rm -rf ${NAME}
	make fclean -C srcs/libft

re:	fclean all

.PHONY:	all clean fclean re

#valgrind -s --suppressions=ignoreleak --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./minishell
