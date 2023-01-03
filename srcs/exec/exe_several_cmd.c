/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_several_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:25:06 by nicole            #+#    #+#             */
/*   Updated: 2023/01/03 17:16:39 by nicole           ###   ########.fr       */
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
	cmd_pipe = ft_split(data->readline, '|');
	while (data->nb_pipe > i)
	{
		if (pipe(fd_pipe + 2 * i) == -1)
			ft_exit(1);
		i++;
	}
	redirect_process(data, cmd_pipe, fd_pipe);
	close_and_wait_process(data, fd_pipe, cmd_pipe);
	ft_free(cmd_pipe);
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
			if (i == 0)
				first_process(data, fd_pipe[1], fd_pipe, cmd_pipe[i]);
			if (data->nb_pipe != i)
				mid_process(data, i, fd_pipe, cmd_pipe[i]);
			if (data->nb_pipe == i)
				end_process(data, fd_pipe[data->nb_pipe * 2 - 2], fd_pipe,
					cmd_pipe[i]);
		}
		i++;
	}
}

void	first_process(t_data *data, int out, int *fd_pipe, char *str)
{
	char	*lst_cmd;
	int		i;
	int		is_hd;

	i = 0;
	is_hd = ft_is_heredoc(str);
	dup2(out, 1);
	while (data->nb_pipe * 2 > i)
	{
		close(fd_pipe[i]);
		i++;
	}
	if (is_hd == 1)
		lst_cmd = ft_rm_heredoc_in_str(data, str);
	else if (ft_is_rd(str) == 0)
		lst_cmd = ft_is_redirect(str, data);
	else
		lst_cmd = ft_expand(data, str);
	if (ft_cmd_is_empty(lst_cmd) == 0)
	{
		ft_choose_fd(is_hd, data, str);
		execute(lst_cmd, data->envp, data);
	}
}

void	mid_process(t_data *data, int i, int *fd_pipe, char *str)
{
	char	*lst_cmd;
	int		in;
	int		out;
	int		is_hd;

	in = fd_pipe[2 * i - 2];
	out = fd_pipe[2 * i + 1];
	is_hd = ft_is_heredoc(str);
	dup2(in, 0);
	dup2(out, 1);
	i = 0;
	while (data->nb_pipe * 2 > i)
	{
		close(fd_pipe[i]);
		i++;
	}
	if (is_hd == 1)
		lst_cmd = ft_rm_heredoc_in_str(data, str);
	else if (ft_is_rd(str) == 0)
		lst_cmd = ft_is_redirect(str, data);
	else
		lst_cmd = ft_expand(data, str);
	if (ft_cmd_is_empty(lst_cmd) == 0)
	{
		ft_choose_fd(is_hd, data, str);
		execute(lst_cmd, data->envp, data);
	}
}

void	end_process(t_data *data, int in, int *fd_pipe, char *str)
{
	char	*lst_cmd;
	int		i;
	int		is_hd;

	i = 0;
	is_hd = ft_is_heredoc(str);
	dup2(in, 0);
	while (data->nb_pipe * 2 > i)
	{
		close(fd_pipe[i]);
		i++;
	}
	if (is_hd == 1)
		lst_cmd = ft_rm_heredoc_in_str(data, str);
	else if (ft_is_rd(str) == 0)
		lst_cmd = ft_is_redirect(str, data);
	else
		lst_cmd = ft_expand(data, str);
	if (ft_cmd_is_empty(lst_cmd) == 0)
	{
		ft_choose_fd(is_hd, data, str);
		execute(lst_cmd, data->envp, data);
	}
}
