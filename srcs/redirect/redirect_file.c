/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:16:39 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/12 14:27:14 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_get_pos_redirect(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1] != '\0' && (i + 1) < (int)ft_strlen(str))
	{
		if ((str[i] == '<' && str[i + 1] != '<')
			|| (str[i] == '>' && str[i + 1] != '>'))
		{
			i++;
			break ;
		}
		else if (str[i] == '>' && str[i + 1] == '>')
		{
			i += 2;
			break ;
		}
		i++;
	}
	if (str[i + 1] == '\0')
		return (-1);
	return (i);
}

void	ft_check_and_close_fd(int fd, char *file, t_data *data)
{
	if (ft_type_of_redirect(data->stmp) == 3 && data->file_exit != 1)
		data->file_in = ft_strdup(file);
	else if (ft_type_of_redirect(data->stmp) == 2 && data->file_exit != 1)
		data->file_out = ft_strdup(file);
	else if (ft_type_of_redirect(data->stmp) == 1 && data->file_exit != 1)
		data->file_out = ft_strdup(file);
	if (fd == -1)
	{
		data->file_exit = 1;
		data->code_exit = 1;
		fd_error(file);
	}
	else
		close(fd);
}

void	ft_open_tmp_file(char *file, t_data *data)
{
	int	i;

	i = 0;
	while (ft_is_space(file[i]) == 0 && file[i] != '\0')
		i++;
	if (ft_type_of_redirect(data->stmp) == 3 && data->file_exit != 1)
	{
		data->type_in = REDIRECT_IN;
		data->fd_in = open(file + i, O_RDONLY);
		ft_check_and_close_fd(data->fd_in, file + i, data);
	}
	else if (ft_type_of_redirect(data->stmp) == 2 && data->file_exit != 1)
	{
		data->type_out = REDIRECT_OUT;
		data->fd_out = open(file + i, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ft_check_and_close_fd(data->fd_out, file + i, data);
	}
	else if (ft_type_of_redirect(data->stmp) == 1 && data->file_exit != 1)
	{
		data->type_dout = D_REDIRECT_OUT;
		data->fd_out = open(file + i, O_RDWR | O_CREAT | O_APPEND);
		ft_check_and_close_fd(data->fd_out, file + i, data);
	}
}

char	*ft_rm_redirect(t_data *data, char *str)
{
	int		i;
	char	*tmp;
	char	*str_exp;

	i = 0;
	tmp = ft_strdup(str);
	while (str[i] != '\0')
	{
		if (i >= ft_before_redirect(tmp) && i <= ft_after_redirect(tmp))
			str[i] = ' ';
		i++;
	}
	str_exp = ft_expand(data, str);
	free(tmp);
	free(str);
	return (str_exp);
}

void	ft_open_all_file(t_data *data, char *str)
{
	int		i;
	int		start;
	char	*file;
	char	char_save;

	data->stmp = ft_strdup(str);
	i = ft_get_pos_redirect(data->stmp);
	while (i != -1)
	{
		start = i;
		while (ft_is_space(data->stmp[i]) == 0 && data->stmp[i] != '\0')
			i++;
		while (ft_is_space(data->stmp[i]) == 1 && data->stmp[i] != '\0')
			i++;
		char_save = data->stmp[i];
		if (data->stmp[i] != '\0')
			data->stmp[i] = '\0';
		file = ft_expand(data, data->stmp);
		ft_open_tmp_file(file + start, data);
		free(file);
		data->stmp[i] = char_save;
		data->stmp = ft_rm_redirect(data, data->stmp);
		i = ft_get_pos_redirect(data->stmp);
	}
}
