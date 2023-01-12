/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:11:18 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/12 14:01:25 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_all(t_data *data)
{
	ft_free_token(data);
	ft_free_tok_exe(data);
	ft_free_data(data);
	if (data->file_in != NULL)
		free(data->file_in);
	if (data->file_out != NULL)
		free(data->file_out);
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
	data->readline = NULL;
}
