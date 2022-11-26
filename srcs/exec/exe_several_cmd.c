/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_several_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:25:06 by nicole            #+#    #+#             */
/*   Updated: 2022/11/26 14:45:47 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//------ var necessaire pour exe multi pipe
//pid_t	proccess_start;
//pid_T	proccess_mid;
//pid_t	proccess_end;
//------
//------parti avec les 3 proccess
/*

	process_start = fork();
	if (process_start == 0)
	{
		first_pipe(data, fd_pipe[i]);
		i++;
	}
	while (data->nb_pipe > i)
	{
		process_mid = fork();
		if (process_mid == 0)
		{
			mid_pipe(data, fd_pipe[i])
			i++;
		}
	}
	process_end = fork();
	if (process_end == 0)
	{
		if (data->nb_pipe == i)
		{
			end_pipe(data, fd_pipe[i]);
			i++;
		}
	}
	waitpid(process_start, &status, 0);
	waitpid(process_mid, &status, 0);
	waitpid(process_end, &status, 0);*/
//------
void	ft_exe_several_cmd(t_data *data)
{
	int		*fd_pipe;
	char	**cmd_pipe;
	int		i;

	i = 0;
	fd_pipe = malloc(sizeof(int) * 2 * data->nb_pipe);
	if (fd_pipe == NULL)
		ft_exit();
	cmd_pipe = ft_split(data->readline, '|');
	while (data->nb_pipe > i)
	{
		if (pipe(fd_pipe + 2 * i) == -1)
			ft_exit();
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
		ft_putnbr_fd(i, 2);
		ft_putstr_fd(" process\n", 2);
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

	i = 0;
	dup2(out, 1);
	while (data->nb_pipe * 2 > i)
	{
		close(fd_pipe[i]);
		i++;
	}
	if (ft_is_heredoc(str) == 1)
		lst_cmd = ft_rm_heredoc_in_str(str);
	else
		lst_cmd = str;
	lst_cmd = ft_rm_quotes(lst_cmd);
	execute(lst_cmd, data->envp, data);
	free(lst_cmd);
}

void	mid_process(t_data *data, int i, int *fd_pipe, char *str)
{
	char	*lst_cmd;
	int		in;
	int		out;

	in = fd_pipe[2 * i - 2];
	out = fd_pipe[2 * i + 1];
	dup2(in, 0);
	dup2(out, 1);
	i = 0;
	while (data->nb_pipe * 2 > i)
	{
		close(fd_pipe[i]);
		i++;
	}
	if (ft_is_heredoc(str) == 1)
		lst_cmd = ft_rm_heredoc_in_str(str);
	else
		lst_cmd = str;
	lst_cmd = ft_rm_quotes(lst_cmd);
	execute(lst_cmd, data->envp, data);
	free(lst_cmd);
}

void	end_process(t_data *data, int in, int *fd_pipe, char *str)
{
	char	*lst_cmd;
	int		i;

	dup2(in, 0);
	i = 0;
	while (data->nb_pipe * 2 > i)
	{
		close(fd_pipe[i]);
		i++;
	}
	if (ft_is_heredoc(str) == 1)
		lst_cmd = ft_rm_heredoc_in_str(str);
	else
		lst_cmd = str;
	lst_cmd = ft_rm_quotes(lst_cmd);
	execute(lst_cmd, data->envp, data);
	free(lst_cmd);
}
