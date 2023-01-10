/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:16:39 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/10 02:19:09 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_get_pos_redirect(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == '>')
		{
			while (ft_is_space(str[i]) == 0)
				i++;
			break ;
		}
	}
	if (str[i] == '\0')
		return (-1);
	return (i);
}

void	ft_check_and_close_fd(int fd, char *file, t_data *data)
{
	if (fd == -1)
	{
		data->file_exit = 1;
		data->code_exit = 1;
		fd_error(file);
	}
	close(fd);
}

void	ft_open_tmp_file(char *file, t_data *data)
{

	if (ft_type_of_redirect(data->stmp) == 3)
	{
		data->type_in = REDIRECT_IN;
		data->file_in = file;
		data->fd_in = open(file, O_RDONLY);
		ft_check_and_close_fd(data->fd_in, file, data);
	}
	else if (ft_type_of_redirect(data->stmp) == 2)
	{
		data->type_out = REDIRECT_OUT;
		data->file_out = file;
		data->fd_out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ft_check_and_close_fd(data->fd_out, file, data);
	}
	else if (ft_type_of_redirect(data->stmp) == 1)
	{
		data->type_dout = D_REDIRECT_OUT;
		data->file_dout = file;
		data->fd_out = open(file, O_RDWR | O_CREAT | O_APPEND);
		ft_check_and_close_fd(data->fd_out, file, data);
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
	char	char_save;

	data->stmp = ft_strdup(str);
	i = ft_get_pos_redirect(data->stmp);
	while (i != -1)
	{
		while (ft_is_space(data->stmp[i]) == 0 && data->stmp[i] != '\0')
			i++;
		while (ft_is_space(data->stmp[i]) == 1 && data->stmp[i] != '\0')
			i++;
		char_save = data->stmp[i];
		data->stmp[i] = '\0';
		data->stmp = ft_expand(data, data->stmp + ft_get_pos_redirect(data->stmp));
		data->stmp[i] = char_save;
		if (data->stmp[ft_strlen(data->stmp)] != '\0')
			data->stmp[ft_strlen(data->stmp)] = '\0';
		ft_open_tmp_file(data->stmp, data);
		data->stmp = ft_rm_redirect(data, data->stmp);
		if (ft_get_pos_redirect(data->stmp) == -1)
			break ;
		free(data->stmp);
		i = ft_get_pos_redirect(data->stmp);
	}
	printf("data->stmp = %s \n", data->stmp);
	free(data->stmp);
}
