/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:36:27 by nicole            #+#    #+#             */
/*   Updated: 2022/12/11 17:02:18 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_rd(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<' && str[i + 1] != '<')
			return (0);
		else if (str[i] == '>' && str[i + 1] != '>')
			return (0);
		else if (str[i] == '>' && str[i + 1] == '>')
			return (0);
		else if (str[i] == '<' && str[i + 1] == '<')
			return (1);
		i++;
	}
	return (1);
}

int	ft_is_rd_in(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<' && str[i + 1] != '<')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_rd_out(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '>' && str[i + 1] != '>')
			return (1);
		else if (str[i] == '>' && str[i + 1] == '>')
			return (2);
		i++;
	}
	return (0);
}

int	ft_type_of_redirect(t_token *tok)
{
	t_token	*tmp;

	tmp = tok;
	while (tmp->next != NULL)
	{
		if (tmp->type == REDIRECT_IN || tmp->type == REDIRECT_OUT
			|| tmp->type == D_REDIRECT_OUT)
			return (tmp->type);
		tmp = tmp->next;
	}
	return (0);
}

char	*ft_is_redirect(char *str, t_data *data)
{
	int		fd;
	char	*file;
	char	*new_str;

	file = ft_rm_str_tok_value(data->token);
	if (ft_type_of_redirect(data->token) == REDIRECT_IN)
		fd = open(file, O_RDONLY);
	else if (ft_type_of_redirect(data->token) == REDIRECT_OUT)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC);
	else if (ft_type_of_redirect(data->token) == D_REDIRECT_OUT)
		fd = open(file, O_RDWR | O_CREAT | O_APPEND);
	if (fd == -1)
	{
		data->code_exit = errno;
		fd_error(file);
	}
	else
		data->last_fd = fd;
	free(file);
	new_str = ft_rm_redirect_in_str(str);
	return (new_str);
}
