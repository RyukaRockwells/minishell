/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_several_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:25:06 by nicole            #+#    #+#             */
/*   Updated: 2022/11/26 11:55:29 by nicole           ###   ########.fr       */
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
	int		status;
	int		i;
	pid_t	proccess;

	i = 0;
	fd_pipe = malloc(sizeof(int) * 2 * data->nb_pipe);
	if (fd_pipe == NULL)
		ft_exit();
	cmd_pipe = ft_split(data->readline, '|');
	while (data->nb_pipe >= i)
	{
		if (pipe(fd_pipe[i]) == -1)
		{
			ft_putstr_fd("Ça foire\n", 2);
			ft_exit();
		}
		i++;
	}
	ft_putnbr_fd(i, 2);
	ft_putstr_fd(" fd_pipe\n", 2);
	i = 0;
	while (data->nb_pipe >= i)
	{
		ft_putnbr_fd(i, 2);
		ft_putstr_fd(" proccess\n", 2);
		proccess = fork();
		if (proccess == 0)
		{
			if (i == 0)
			{
				ft_putstr_fd("debut\n", 2);
				ft_putstr_fd(cmd_pipe[i], 2);
				ft_putstr_fd("\n", 2);
				first_pipe(data, fd_pipe[i], cmd_pipe[i]);
			}
			if (data->nb_pipe != i)
			{
				ft_putstr_fd("milieu\n", 2);
				ft_putstr_fd(cmd_pipe[i], 2);
				ft_putstr_fd("\n", 2);
				mid_pipe(data, fd_pipe[i], cmd_pipe[i]);
			}
			if (data->nb_pipe == i)
			{
				ft_putstr_fd("fin\n", 2);
				ft_putstr_fd(cmd_pipe[i], 2);
				ft_putstr_fd("\n", 2);
				end_pipe(data, fd_pipe[i], cmd_pipe[i]);
			}
		}
		i++;
		waitpid(proccess, &status, 0);
	}
	ft_free(cmd_pipe);
}

void	first_pipe(t_data *data, int *fd_pipe, char *str)
{
	//(void)data;
	//(void)fd_pipe;
	pid_t	p_exe;
	int		status;
	char	*lst_cmd;

	ft_putstr_fd("first_pipe\n", 2);
	close(fd_pipe[0]);
	if (ft_is_heredoc(str) == 1)
		lst_cmd = ft_rm_heredoc_in_str(str);
	else
		lst_cmd = str;
	lst_cmd = ft_rm_quotes(lst_cmd);
	p_exe = fork();
	if (p_exe == 0)
		execute(lst_cmd, data->envp, data);
	waitpid(p_exe, &status, 0);
	free(lst_cmd);
	//exit(EXIT_SUCCESS);
}

void	mid_pipe(t_data *data, int *fd_pipe, char *str)
{
	//(void)data;
	pid_t	p_exe;
	int		status;
	char	*lst_cmd;

	(void)fd_pipe;
	ft_putstr_fd("mid_pipe\n", 2);
	if (ft_is_heredoc(str) == 1)
		lst_cmd = ft_rm_heredoc_in_str(str);
	else
		lst_cmd = str;
	lst_cmd = ft_rm_quotes(lst_cmd);
	p_exe = fork();
	if (p_exe == 0)
		execute(lst_cmd, data->envp, data);
	waitpid(p_exe, &status, 0);
	free(lst_cmd);
	//exit(EXIT_SUCCESS);
}

void	end_pipe(t_data *data, int *fd_pipe, char *str)
{
	//(void)data;
	//(void)fd_pipe;
	pid_t	p_exe;
	int		status;
	char	*lst_cmd;

	ft_putstr_fd("end_pipe\n", 2);
	close(fd_pipe[1]);
	if (ft_is_heredoc(str) == 1)
		lst_cmd = ft_rm_heredoc_in_str(str);
	else
		lst_cmd = str;
	lst_cmd = ft_rm_quotes(lst_cmd);
	p_exe = fork();
	if (p_exe == 0)
		execute(lst_cmd, data->envp, data);
	waitpid(p_exe, &status, 0);
	free(lst_cmd);
	//exit(EXIT_SUCCESS);
}
