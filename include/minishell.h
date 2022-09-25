/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:10:38 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/25 18:28:39 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "../srcs/libft/libft.h"

# define LITERAL 1
# define PIPE 2
# define REDIRECT_IN 3
# define REDIRECT_OUT 4
# define D_REDIRECT_OUT 5
# define S_QUOTES 6
# define D_QUOTES 7
# define ESPACE 8
# define HEREDOC 9
# define CMD 10

# define QUOTES_NO_CLOSE 20
# define EMPTY_TOK 21
# define PIPE_ERROR 22
# define ERROR 23
# define REDIR_IN_ERROR 24
# define REDIR_OUT_ERROR 25
# define D_REDIR_OUT_ERROR 26
# define HEREDOC_ERROR 27
# define NEWLINE_ERROR 28

//struct a revoir

typedef struct s_token		t_token;
typedef struct s_data		t_data;
typedef struct s_here_tok	t_here_tok;
typedef struct s_exe		t_exe;

typedef struct s_here_tok
{
	int			fd;
	t_here_tok	*next;
}			t_here_fd;

typedef struct s_token
{
	char	*value;
	int		type;
	t_token	*next;
}				t_token;

typedef struct s_exe
{
	char	**cmd;
	int		in;
	int		out;
	int		i;
	int		pb;
	pid_t	pid;
	t_exe	*next;
}			t_exe;

/*
typedef struct s_exec_elm
{
	char				**cmd;
	int					fd_in;
	int					fd_out;
	int					index;
	int					has_redirect_pb;
	pid_t				pid;
	struct s_exec_elm	*next;

}	t_exec_elm;
*/

typedef struct s_data
{
	int			code_exit;
	char		*readline;
	char		**envp;
	int			nb_pipe; //for multi-pipe
	t_token		*token;
	t_token		*tok_exe;
	t_exe		*exe;
	int			fd_stdout;
	int			fd_stdin;
	t_data		*data;
	t_here_tok	*here_fd;
}				t_data;

//ft_deco.c
void	ft_deco(void);
//ft_error.c
void	ft_error(void);
void	ft_error_env(void);
void	show_error(int code_error);
//ft_init.c
void	ft_init(char **envp, t_data *data);
void	ft_reinit(t_data *data);
int		ft_env_nbline(char **envp);
void	ft_env(t_data *data, char **envp);
//void	ft_print_env(t_data *data);
//ft_loop.c
int		ft_get_cmd(t_data *data);
void	ft_tok(t_data *data);
void	ft_loop(t_data *data);
t_token	*ft_sep_redtok(t_data *data, t_token *tmp);
int		ft_chose_tok(t_data *data, char *value, int type);
//exit.c
char	**ft_free(char **tab);
void	ft_exit(t_data *data);
void	ft_free_token_list(t_data *data);
//signal.c
void	ft_catch_signal(void);
void	ft_catch_d(t_data *data);
void	ft_catch_int(int signal);
//lexer/lexer.c
int		ft_lexer(t_data *data);
int		ft_parser(t_data *data);
int		ft_get_word(t_data *data, int i);
int		ft_get_sep(t_data *data, int i);
int		ft_word_quote(char *str, int i, char c);
//lexer/lexer_utils.c
int		ft_is_space(char c);
int		ft_is_separator(char c);
int		ft_wdlen(char *str, int i);
int		ft_add_space(t_data *data, char *str, int i);
int		ft_redirect(t_data *data, char *str, int i);
//lexer/lexer_check.c
int		ft_check_metachar(char *str, int i);
int		ft_check_quotes(char *str);
void	ft_check_squotes(char *str, int *i, int *j);
void	ft_check_dquotes(char *str, int *i, int *j);
//main.c
void	minishell(char **arg, char **envp);
//token/token.c
int		ft_get_token(t_data *data, char *rdline, int i, int strlen);
void	ft_add_token(char *word, t_data *data, int type);
void	ft_addtok(char *word, t_data *data, int type);
void	show_token2(t_data *data);
void	show_token(t_data *data);
//token/token_list.c
void	ft_tokenadd_back(t_token **tok, t_token *new);
t_token	*ft_tokenlast(t_token *tok);
//parser/parser2.c
int		ft_pipe(t_token *tok);
int		ft_parser(t_data *data);
//parser/parser_check2.c
int		ft_empty_tok(t_token *tok);
int		ft_pre_check(t_token *tok);
int		ft_check_redirect(t_token *tmp);
int		ft_check_next_tok(int type);
//pre_exec/create_list.c
t_exe	*ft_create_list(t_data *data, int nb_pipe);
t_exe	*ft_new_exelst(t_data *data);
void	show_exe(t_data *data);
void	ft_fd_exec(t_data *data);
int		*ft_create_pipe(t_data *data);
//pre_exec/exe_list.c
t_exe	*ft_get_idexe(t_exe *exe, int i);
int		ft_nb_pipe(t_token *lst);
void	ft_exe_lst(t_data *data);
t_exe	ft_addexe(t_exe **exe, t_exe *new);
t_exe	*ft_exelast(t_exe *exe);

#endif
