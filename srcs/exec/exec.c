/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:41:32 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/08 22:05:54 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exe_cmd(t_data *data)
{
	int		i;
	char	**split_pipe;

	i = 0;
	while (data->readline[i] != '\0')
	{
		if (data->readline[i] == '<'
			&& data->readline[i] == data->readline[i + 1])
			return ;
		if (data->readline[i] != ' ')
			break ;
		i++;
	}
	i = 0;
	split_pipe = ft_split_quote(data->readline, '|');
	while (split_pipe[i] != NULL)
		i++;
	ft_free_tab(split_pipe);
	if (i == 1)
		ft_exe_simple_cmd(data);
	else if (i > 1)
		ft_exe_several_cmd(data);
	data->file_exit = 0;
}

void	ft_choose_fd(int is_hd, t_data *data, char *str)
{
	if ((is_hd == 1 || ft_is_rd_in(str) == 0) && data->last_fd != -1)
	{
		dup2(data->last_fd, 0);
		close(data->last_fd);
	}
	else if (ft_is_rd_out(str) != 0 && data->last_fd != -1)
	{
		dup2(data->last_fd, 1);
		close(data->last_fd);
	}
}

char	*check_path(char **path, char *cmd)
{
	char	*one_path;
	char	*tab_path;
	int		i;

	i = -1;
	while (path[++i] != NULL)
	{
		tab_path = ft_strjoin(path[i], "/");
		check_path_null(tab_path, cmd, path);
		one_path = ft_strjoin(tab_path, cmd);
		check_opath_null(tab_path, one_path, cmd, path);
		free(tab_path);
		if (access(one_path, F_OK) == 0)
		{
			ft_free_tab(path);
			return (one_path);
		}
		free(one_path);
	}
	ft_free_tab(path);
	return (0);
}

char	*find_path(char **cmd, char **envp, t_data *data, char *lst_cmd)
{
	char	**paths;
	int		i;

	i = 0;
	if (ft_strnstr(cmd[0], "/", ft_strlen(cmd[0])) != 0)
		if (access(cmd[0], F_OK) == 0)
			return (cmd[0]);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) != 0)
			i++;
		else
			break ;
	}
	if (envp[i] == NULL)
		ft_exit_no_path(data, cmd, lst_cmd);
	paths = ft_split(envp[i] + 5, ':');
	if (paths == NULL)
	{
		free(cmd[0]);
		ft_error();
	}
	return (check_path(paths, cmd[0]));
}

void	execute(char *lst_cmd, char **envp, t_data *data)
{
	char	**cmd;
	char	*path;

	cmd = ft_split_quote(lst_cmd, ' ');
	if (cmd == NULL)
		ft_error();
	path = find_path(cmd, envp, data, lst_cmd);
	if (path == 0)
		ft_error_exe(data, cmd, lst_cmd);
	if (data->file_exit == 0)
	{
		if (execve(path, cmd, envp) == -1)
		{
			free(path);
			ft_error_exe(data, cmd, lst_cmd);
		}
	}
	ft_free_exe_simple(data, cmd, lst_cmd);
	free(path);
	ft_exit(data->code_exit);
}
