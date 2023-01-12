/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:36:27 by nicole            #+#    #+#             */
/*   Updated: 2023/01/12 16:13:49 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_return_fd_in(int return_in, t_data *data)
{
	if (return_in == 1)
		return (data->fd_in);
	else if (return_in == 2)
		return (data->last_fd);
	return (0);
}

int	ft_get_rd_in(char *str, t_data *data)
{
	int	i;
	int	return_in;

	i = 0;
	return_in = 0;
	while (str[i + 1] != '\0')
	{
		if (i == 0)
		{
			if (str[i] == '<' && str[i + 1] != '<')
				return_in = 1;
			else if (str[i] == '<' && str[i + 1] == '<')
				return_in = 2;
		}
		else if (str[i + 2] != '\0')
		{
			if (str[i - 1] != '<' && str[i] == '<' && str[i + 1] != '<')
				return_in = 1;
			else if (str[i] == '<' && str[i + 1] == '<')
				return_in = 2;
		}
		i++;
	}
	return (ft_return_fd_in(return_in, data));
}

int	ft_is_rd_in(t_data *data)
{
	t_token	*tmp;
	int		return_in;

	tmp = data->token;
	while (tmp != NULL)
	{
		if (tmp->type == REDIRECT_IN)
			return_in = 1;
		else if (tmp->type == HEREDOC)
			return_in = 2;
		tmp = tmp->next;
	}
	if (return_in == 1)
		return (data->fd_in);
	else
		return (data->last_fd);
}

int	ft_type_of_redirect(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '>' && str[i + 1] == '>')
			return (1);
		else if (str[i] == '>')
			return (2);
		else if (str[i] == '<')
			return (3);
		i++;
	}
	return (0);
}

char	*ft_is_redirect(char *str, t_data *data)
{
	ft_open_all_file(data, str);
	if (data->type_in == REDIRECT_IN && data->file_exit != 1)
		data->fd_in = open(data->file_in, O_RDONLY);
	if (data->type_out == REDIRECT_OUT && data->file_exit != 1)
		data->fd_out = open(data->file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->type_dout == D_REDIRECT_OUT && data->file_exit != 1)
		data->fd_out = open(data->file_out, O_RDWR | O_CREAT | O_APPEND);
	if (data->file_in != NULL)
	{
		free(data->file_in);
		data->file_in = NULL;
	}
	if (data->file_out != NULL)
	{
		free(data->file_out);
		data->file_out = NULL;
	}
	return (data->stmp);
}
