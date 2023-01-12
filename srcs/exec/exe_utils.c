/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:21:49 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/12 18:07:44 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_and_wait_process(t_data *data, int *fd_pipe, char **cmd_pipe)
{
	int	i;
	int	status;
	int	pid;
	int	oldpid;
	int	max_status;

	i = 0;
	pid = 0;
	oldpid = 0;
	max_status = 0;
	while (data->nb_pipe * 2 > i)
		close(fd_pipe[i++]);
	free(fd_pipe);
	ft_signore();
	i = 0;
	while (cmd_pipe[i] != NULL)
	{
		pid = waitpid(0, &status, 0);
		if (pid >= oldpid)
			max_status = status;
		oldpid = pid;
		i++;
	}
	ft_sigreset();
	ft_set_code_exit(data, max_status);
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
