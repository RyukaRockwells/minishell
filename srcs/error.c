/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:26:20 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/11 17:48:46 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
		ft_putstr_fd("This is a hole\n", 2);
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
		ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
	if (code_error == ERROR)
		ft_putstr_fd("minishell: error\n", 2);
}