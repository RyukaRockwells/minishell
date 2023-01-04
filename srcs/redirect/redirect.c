/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:36:27 by nicole            #+#    #+#             */
/*   Updated: 2023/01/04 00:32:13 by nicole           ###   ########.fr       */
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
	int		fd;
	char	*file;
	char	*new_str;

	file = ft_get_file(data, str);
	if (ft_type_of_redirect(str) == 3)
		fd = open(file, O_RDONLY);
	else if (ft_type_of_redirect(str) == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (ft_type_of_redirect(str) == 1)
		fd = open(file, O_RDWR | O_CREAT | O_APPEND);
	if (fd == -1)
	{
		data->file_exit = 1;
		data->code_exit = 1;
		fd_error(file);
	}
	else
		data->last_fd = fd;
	free(file);
	new_str = ft_rm_redirect_in_str(data, str);
	return (new_str);
}
