/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_several_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:25:06 by nicole            #+#    #+#             */
/*   Updated: 2023/01/11 22:15:36 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exe_several_cmd(t_data *data)
{
	int		*fd_pipe;
	char	**cmd_pipe;
	int		i;

	i = 0;
	fd_pipe = malloc(sizeof(int) * 2 * data->nb_pipe);
	if (fd_pipe == NULL)
		ft_exit(1);
	cmd_pipe = ft_split_quote(data->readline, '|');
	while (data->nb_pipe > i)
	{
		if (pipe(fd_pipe + 2 * i) == -1)
			ft_exit(1);
		i++;
	}
	redirect_process(data, cmd_pipe, fd_pipe);
	close_and_wait_process(data, fd_pipe, cmd_pipe);
	ft_free_tab(cmd_pipe);
}

void	redirect_process(t_data *data, char **cmd_pipe, int *fd_pipe)
{
	int		i;
	pid_t	process;

	i = 0;
	while (cmd_pipe[i] != NULL)
	{
		process = fork();
		if (process == 0)
		{
			ft_default_signal_child();
			if (i == 0)
				first_process(data, cmd_pipe, fd_pipe, cmd_pipe[i]);
			if (data->nb_pipe != i)
				mid_process(data, i, fd_pipe, cmd_pipe);
			if (data->nb_pipe == i)
				end_process(data, cmd_pipe, fd_pipe, cmd_pipe[i]);
		}
		i++;
	}
}

void	first_process(t_data *data, char **tab_cmd, int *fd_pipe, char *str)
{
	char	*lst_cmd;
	int		i;
	int		is_hd;
	int		return_dup;

	i = 0;
	is_hd = ft_is_heredoc(str);
	return_dup = dup2(fd_pipe[1], 1);
	while (data->nb_pipe * 2 > i)
	{
		close(fd_pipe[i]);
		i++;
	}
	free(fd_pipe);
	lst_cmd = ft_rdline_choose(is_hd, data, str);
	if (ft_cmd_is_empty(lst_cmd) == 0)
	{
		ft_choose_fd(is_hd, data);
		if (ft_builtin(data, lst_cmd) != 2)
			ft_free_builtin(lst_cmd, tab_cmd);
		ft_free_tab(tab_cmd);
		execute(lst_cmd, data->envp, data);
	}
	free(lst_cmd);
	ft_free_tab(tab_cmd);
}

void	mid_process(t_data *data, int i, int *fd_pipe, char **tab_cmd)
{
	char	*lst_cmd;
	int		i_cmd_active;
	int		is_hd;

	i_cmd_active = i;
	is_hd = ft_is_heredoc(tab_cmd[i]);
	dup2(fd_pipe[2 * i - 2], 0);
	dup2(fd_pipe[2 * i + 1], 1);
	i = 0;
	while (data->nb_pipe * 2 > i)
		close(fd_pipe[i++]);
	free(fd_pipe);
	lst_cmd = ft_rdline_choose(is_hd, data, tab_cmd[i_cmd_active]);
	if (ft_cmd_is_empty(lst_cmd) == 0)
	{
		ft_choose_fd(is_hd, data);
		if (ft_builtin(data, lst_cmd) != 2)
			ft_free_builtin(lst_cmd, tab_cmd);
		ft_free_tab(tab_cmd);
		execute(lst_cmd, data->envp, data);
	}
	free(lst_cmd);
	ft_free_tab(tab_cmd);
}

void	end_process(t_data *data, char **tab_cmd, int *fd_pipe, char *str)
{
	char	*lst_cmd;
	int		i;
	int		is_hd;

	i = 0;
	is_hd = ft_is_heredoc(str);
	dup2(fd_pipe[data->nb_pipe * 2 - 2], 0);
	while (data->nb_pipe * 2 > i)
	{
		close(fd_pipe[i]);
		i++;
	}
	free(fd_pipe);
	lst_cmd = ft_rdline_choose(is_hd, data, str);
	if (ft_cmd_is_empty(lst_cmd) == 0)
	{
		ft_choose_fd(is_hd, data);
		if (ft_builtin(data, lst_cmd) != 2)
			ft_free_builtin(lst_cmd, tab_cmd);
		ft_free_tab(tab_cmd);
		execute(lst_cmd, data->envp, data);
	}
	free(lst_cmd);
	ft_free_tab(tab_cmd);
}
