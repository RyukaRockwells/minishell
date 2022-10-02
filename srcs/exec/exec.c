/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:41:32 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/02 18:47:13 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exe_cmd(t_data *data)
{
	if (data->nb_pipe == 0)
		ft_exe_cmd_simple(data);
	/*else
		ft_exe_cmd_pipe(data);*/
}

void	ft_exe_cmd_pipe(t_data *data)
{
	int		i;
	int		pipefd[2];
	pid_t	pid;

	i = 0;
	while (i < data->nb_pipe)
	{
		pipe(pipefd);
		pid = fork();
		if (pid == 0)
		{
			dup2(pipefd[1], 1);
			close(pipefd[0]);
			ft_exe_cmd_simple(data);
			exit(0);
		}
		else
		{
			dup2(pipefd[0], 0);
			close(pipefd[1]);
			waitpid(pid, NULL, 0);
			i++;
		}
	}
	ft_exe_cmd_simple(data);
}

void	ft_exe_cmd_simple(t_data *data)
{
	char	*path;
	char	**envp;
	int		i;

	i = 0;
	path = NULL;
	envp = ft_lst_to_tab(data->envp);
	/*while (envp[i] != NULL)
		printf("%s\n", envp[i++]);*/
	if (data->exe->cmd[0] != NULL)
	{
		printf("cmd[0] = %s\n", data->exe->cmd[0]);
	}
	else
		printf("cmd[0] = NULL\n");
		/*if (ft_strchr(data->exe->cmd[0], '/') != NULL)
			path = ft_strdup(data->exe->cmd[0]);
		else
			path = ft_find_path(data->exe->cmd[0], data->path);
		if (path != NULL)
		{
			if (execve(path, data->exe->cmd, envp) == -1)
				ft_error(data, data->exe->cmd[0], 1);
		}
		else
			ft_error(data, data->exe->cmd[0], 1);
	}
	ft_free_tab(envp);
}*/

char	**ft_lst_to_tab(char **envp)
{
	int		i;
	char	**tab;

	i = 0;
	tab = NULL;
	while (envp[i] != NULL)
		i++;
	tab = malloc(sizeof(char *) * (i + 1));
	if (tab == NULL)
		ft_putstr_fd("malloc error", 2);
	i = 0;
	while (envp[i] != NULL)
	{
		tab[i] = ft_strdup(envp[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
