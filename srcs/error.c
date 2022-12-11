/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:26:20 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/12/11 16:17:40 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_error_exe(t_data *data, char **cmd, char *av)
{
	ft_free_exe_simple(data, cmd, av);
	perror("Error ");
	exit(EXIT_FAILURE);
}

void	fd_error(char *file)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_error(void)
{
	ft_putendl_fd("minishell: command not found", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_env(void)
{
	ft_putendl_fd("minishell: env: no such file or directory", 2);
	exit(EXIT_FAILURE);
}

void	show_error(int code_error)
{
	if (code_error == QUOTES_NO_CLOSE)
		ft_putstr_fd("minishell: quotes no close\n", 2);
	if (code_error == EMPTY_TOK)
		ft_putstr_fd("\n", 2);
	if (code_error == PIPE_ERROR)
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
	if (code_error == REDIR_IN_ERROR)
		ft_putstr_fd("minishell: syntax error near unexpected token `<'\n", 2);
	if (code_error == REDIR_OUT_ERROR)
		ft_putstr_fd("minishell: syntax error near unexpected token `>'\n", 2);
	if (code_error == D_REDIR_OUT_ERROR)
		ft_putstr_fd("minishell: syntax error near unexpected token `>>'\n", 2);
	if (code_error == HEREDOC_ERROR)
		ft_putstr_fd("minishell: syntax error near unexpected token `<<'\n", 2);
	if (code_error == NEWLINE_ERROR)
		ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n" \
		, 2);
	if (code_error == ERROR)
		ft_putstr_fd("minishell: error\n", 2);
}
