/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:36:27 by nicole            #+#    #+#             */
/*   Updated: 2023/01/11 17:35:06 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_rd_in(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp != NULL)
	{
		if (tmp->type == REDIRECT_IN || tmp->type == HEREDOC)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_type_of_redirect(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '>' && str[i + 1] == '>')//out
			return (1);
		else if (str[i] == '>')//out
			return (2);
		else if (str[i] == '<')//in
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
	return (data->stmp);
}
