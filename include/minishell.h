/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:10:38 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/19 18:38:18 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "../srcs/libft/libft.h"

# define LITERAL 1
# define PIPE 2
# define REDIRECT_IN 3
# define REDIRECT_OUT 4
# define OR 5
# define AND 6
# define S_QUOTES 7
# define D_QUOTES 8

# define QUOTES_NO_CLOSE 11
//struct a revoir

typedef struct s_token	t_token;

typedef struct s_token
{
	char	*value;
	int		type;
	t_token	*next;
}				t_token;

typedef struct s_data
{
	int		code_exit;
	char	*readline;
	char	**envp;
	int		nb_process;
	t_token	*token;
	int		fd_stdout;
	int		fd_stdin;
	t_list	*list;
}				t_data;

//ft_deco.c
void	ft_deco(void);
//ft_error.c
void	ft_error(void);
void	ft_error_env(void);
void	show_error(int code_error);
//ft_init.c
void	ft_init(char **envp, t_data *list);
int		ft_env_nbline(char **envp);
void	ft_env(t_data *list, char **envp);
//ft_loop.c
int		ft_get_cmd(t_data *list);
void	ft_loop(t_data *list);
//exit.c
void	ft_exit(t_data *list);
//signal.c
void	ft_catch_signal(void);
void	ft_catch_d(t_data *list);
void	ft_catch_quit(int signal);
void	ft_catch_int(int signal);
//lexer.c
int		ft_lexer(t_data *list);
int		ft_parser(t_data *list);
//lexer_utils.c
int		ft_is_space(char c);
int		ft_is_separator(char c);
int		ft_check_quotes(char *str);
//main.c
void	minishell(char **arg, char **envp);

#endif
