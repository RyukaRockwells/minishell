/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:21:49 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/11/30 09:35:36 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_heredoc(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<' && str[i] == str[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	close_and_wait_process(t_data *data, int *fd_pipe, char **cmd_pipe)
{
	int	i;
	int	status;

	i = 0;
	while (data->nb_pipe * 2 > i)
	{
		close(fd_pipe[i]);
		i++;
	}
	free(fd_pipe);
	i = 0;
	while (cmd_pipe[i] != NULL)
	{
		waitpid(0, &status, 0);
		i++;
	}
}

void	check_path_null(char *tab_path, char *cmd, char **path)
{
	if (tab_path == NULL)
	{
		free(cmd);
		ft_free(path);
		exit(EXIT_FAILURE);
	}
}

void	check_opath_null(char *tab_path, char *o_path, char *cmd, char **path)
{
	if (o_path == NULL)
	{
		free(tab_path);
		free(cmd);
		ft_free(path);
		exit(EXIT_FAILURE);
	}
}

int	ft_cmd_is_empty(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
