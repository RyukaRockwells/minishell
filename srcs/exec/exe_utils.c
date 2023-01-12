/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:21:49 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/06 16:46:10 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	ft_signore();
	i = 0;
	while (cmd_pipe[i] != NULL)
	{
		waitpid(0, &status, 0);
		i++;
	}
	ft_sigreset();
}

void	check_path_null(char *tab_path, char *cmd, char **path)
{
	if (tab_path == NULL)
	{
		free(cmd);
		ft_free_tab(path);
		exit(EXIT_FAILURE);
	}
}

void	check_opath_null(char *tab_path, char *o_path, char *cmd, char **path)
{
	if (o_path == NULL)
	{
		free(tab_path);
		free(cmd);
		ft_free_tab(path);
		exit(EXIT_FAILURE);
	}
}

void	ft_set_code_exit(t_data *data, int status)
{
	if (WIFEXITED(status) == 1)
		data->code_exit = WEXITSTATUS(status);
	else if (WIFSIGNALED(status) == 1)
		data->code_exit = WTERMSIG(status);
	else
		data->code_exit = 0;
}
