/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:16:16 by nicole            #+#    #+#             */
/*   Updated: 2022/10/24 15:18:55 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exe_cmd_simple(t_data *data)
{
	pid_t	p_exe;
	int		status;
	char	*lst_cmd;

	lst_cmd = ft_rm_quotes(data);
	//ft_rm_quotes_token(data);
	p_exe = fork();
	if (p_exe == 0)
		execute(lst_cmd, data->envp);
	waitpid(p_exe, &status, 0);
	free(lst_cmd);
}
//a remplacer
char	*check_path(char **path, char *cmd)
{
	char	*one_path;
	char	*tab_path;
	int		i;

	i = 0;
	while (path[i++] != NULL)
	{
		tab_path = ft_strjoin(path[i], "/");
		if (tab_path == NULL)
		{
			free(cmd);
			ft_free(path);
			exit(EXIT_FAILURE);
		}
		one_path = ft_strjoin(tab_path, cmd);
		if (one_path == NULL)
		{
			free(tab_path);
			free(cmd);
			ft_free(path);
			exit(EXIT_FAILURE);
		}
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

void	execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	if (cmd == NULL)
		ft_error();
	path = find_path(cmd[0], envp);
	if (path == 0)
	{
		ft_free(cmd);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_free(cmd);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	free(path);
	ft_free(cmd);
}
