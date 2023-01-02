/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:10:38 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/02 20:43:11 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "struct.h"
# include "parsing.h"
# include "execution.h"
# include "builtins.h"
# include "../srcs/libft/libft.h"
# include "../srcs/get_next_line/get_next_line_bonus.h"

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
# define EXIT_HEREDOC 130

//ft_deco.c
void	ft_deco(void);

//ft_error.c
void	ft_error_exe(t_data *data, char **cmd, char *av);
void	fd_error(char *file);
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
void	ft_free(char **tab);
void	ft_exit(void);
void	ft_exit_here(void);

//main.c
void	minishell(char **arg, char **envp);

//****-----------------****
//****-----SIGNAL------****
//****-----------------****

//signal.c
void	ft_catch_signal(void);
void	ft_catch_d(t_data *data);
void	ft_catch_int(int signal);
void	ft_sigint(int sig);
void	ft_catch_ctrld_h(t_data *data, char *eof);

//signal2.c
void	ft_catch_c_heredoc(void);

//****-----------------****
//****-------FREE------****
//****-----------------****

//free/all_free.c
void	ft_free_all(t_data *data);
void	ft_free_token(t_data *data);
void	ft_free_tok_exe(t_data *data);
void	ft_free_data(t_data *data);
void	ft_free_exe(t_data *data);

//free/all_free2.c
void	ft_free_tab(char **envp);
void	ft_free_exe_simple(t_data *data, char **cmd, char *av);

//****-----------------****
//****------SHOW-------****
//****-----------------****

//show/show.c
void	show_token2(t_data *data);
void	show_token(t_data *data);

//****-----------------****
//****-----HEREDOC-----****
//****-----------------****

//heredoc/heredoc.c
void	ft_close_here(t_data *data);
int		ft_check_heredoc(t_data *data, t_token *here_tok);
void	ft_read_heredoc(int fd, t_data *data, char *str_here);

//heredoc/heredoc_utils.c
int		ft_is_heredoc(char *str);
void	ft_waitpid_h(t_data *data, int i);

//****-----------------****
//****------UTILS------****
//****-----------------****
//utils/utils.c
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, char *str);
char	**ft_split_quote(char const *s, char c);
int		ft_pass_word(char *s, char c, int i);

//****-----------------****
//****------EXPAND-----****
//****-----------------****
//expand/expand.c
int		ft_exp_is_exist(char *str);
char	*ft_expand_h(int fd, char *str);
char	*ft_expand(char *str);

//expand/expand_utils.c
int		ft_length_name_var(int i, char *str);
int		ft_length_end_var(int length, char *str);
int		ft_get_last_id_var(char *str);
char	*ft_get_var(char *str, int i, int length);
int		ft_skip_name_var(char *str, int i);

#endif
