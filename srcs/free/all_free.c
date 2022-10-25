/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:11:18 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/25 17:21:29 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_all(t_data *data)
{
	ft_free_token(data);
	ft_free_tok_exe(data);
	ft_free_exe(data);
	ft_free_fd_heredoc(data);
	ft_free_data(data);
}

void	ft_free_token(t_data *data)
{
	t_token	*tok;

	while (data->token != NULL)
	{
		tok = data->token;
		data->token = data->token->next;
		free(tok->value);
		tok->value = NULL;
		free(tok);
	}
}

void	ft_free_tok_exe(t_data *data)
{
	t_token	*tok_exe;

	while (data->tok_exe != NULL)
	{
		tok_exe = data->tok_exe;
		data->tok_exe = data->tok_exe->next;
		tok_exe->value = NULL;
		free(tok_exe);
	}
}

void	ft_free_data(t_data *data)
{
	free(data->readline);
}

void	ft_free_exe(t_data *data)
{
	t_exe	*exe;
	int		i;

	i = 0;
	while (data->exe != NULL)
	{
		exe = data->exe;
		data->exe = data->exe->next;
		free(exe->cmd);
		exe->cmd = NULL;
		while (i < data->nb_pipe - 1)
		{
			close(exe->in);
			close(exe->out);
		}
		free(exe);
	}
	free(data->exe);
}
