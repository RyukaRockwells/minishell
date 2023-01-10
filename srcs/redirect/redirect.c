/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:36:27 by nicole            #+#    #+#             */
/*   Updated: 2023/01/10 02:19:33 by nchow-yu         ###   ########.fr       */
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

/*char	*ft_is_redirect(char *str, t_data data)
{
	int		i;
	char	*redirect;

	i = 0;
	redirect = ft_strdup(str);
	while (redirect[i] != '\0')
	{
		if (st[i] == )
	}
}

char	*ft_is_redirect(char *str, t_data *data)
{
	int		fd;
	char	*file;
	char	*new_str;

	fd = 0;
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
	// rajouter dans la structure last_fd_in and last_fd_out 
	free(file);
	new_str = ft_rm_redirect_in_str(data, str);
	fprintf(stderr, "redirect = %s\n", new_str);
	return (new_str);
}*/

char	*ft_is_redirect(char *str, t_data *data)
{
	(void)str;
	ft_open_all_file(data, str);
	if (data->type_in == REDIRECT_IN)
	{
		data->fd_in = open(data->file_in, O_RDONLY);
		fprintf(stderr, "fd = %d\n", data->fd_in);
	}
	if (data->type_out == REDIRECT_OUT)
	{
		data->fd_in = open(data->file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		fprintf(stderr, "fd = %d\n", data->fd_out);
	}
	if (data->type_out == D_REDIRECT_OUT)
	{
		data->fd_in = open(data->file_out, O_RDWR | O_CREAT | O_APPEND);
		fprintf(stderr, "fd = %d\n", data->fd_out);
	}
	fprintf(stderr, "redirect = %s\n", data->stmp);
	return (data->stmp);
}
