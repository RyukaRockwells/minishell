/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:16:16 by nicole            #+#    #+#             */
/*   Updated: 2022/11/26 15:08:31 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exe_cmd_simple(t_data *data)
{
	pid_t	p_exe;
	int		status;
	char	*lst_cmd;

	if (ft_is_heredoc(data->readline) == 1)
		lst_cmd = ft_rm_heredoc_in_str(data->readline);
	else
		lst_cmd = data->readline;
	lst_cmd = ft_rm_quotes(lst_cmd);
	p_exe = fork();
	if (p_exe == 0)
		execute(lst_cmd, data->envp, data);
	waitpid(p_exe, &status, 0);
	free(lst_cmd);
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
		check_opath_null(tab_path, one_path, cmd, path)
		free(tab_path);
		if (access(one_path, F_OK) == 0)
			return (one_path);
		free(one_path);
	}
	ft_free(path);
	return (0);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)) != 0)
		if (access(cmd, F_OK) == 0)
			return (cmd);
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (paths == NULL)
	{
		free(cmd);
		ft_error();
	}
	return (check_path(paths, cmd));
}

void	execute(char *av, char **envp, t_data *data)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	if (cmd == NULL)
		ft_error();
	path = find_path(cmd[0], envp);
	if (path == 0)
	{
		ft_free_exe_simple(data, cmd, av);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd("Error : ", 2);
		ft_putstr_fd(strerror(errno), 2);
		data->code_exit = errno;
		ft_free_exe_simple(data, cmd, av);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	ft_free_exe_simple(data, cmd, av);
	free(path);
}
