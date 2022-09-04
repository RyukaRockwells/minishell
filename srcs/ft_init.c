/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:35:11 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/19 20:23:25 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_init(char **envp, t_data *data)
{
	data->code_exit = 0;
	data->readline = NULL;
	data->envp = NULL;
	data->nb_process = 0;
	data->token = NULL;
	data->fd_stdout = -1;
	data->fd_stdin = -1;
	data->data = data;
	ft_env(data, envp);
}

void	ft_reinit(t_data *data)
{
	data->readline = NULL;
	data->nb_process = 0;
	data->token = NULL;
}

int	ft_env_nbline(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}

void	ft_env(t_data *data, char **envp)
{
	int		i;

	i = 0;
	data->envp = malloc(sizeof(char *) * (ft_env_nbline(envp) + 1));
	if (data->envp == NULL)
		ft_putstr_fd("malloc error", 2);
	while (i < ft_env_nbline(envp) + 1)
	{
		data->envp[i] = NULL;
		i++;
	}//NULL ?
	i = 0;
	while (envp[i] != NULL)
	{
		data->envp[i] = ft_strdup((const char *)envp[i]);
		i++;
	}//free(data->envp);
}
/*char	*line;

ft_deco();
while (1)
{
	line = readline("Minishell> ");
	add_history(line);
	ft_check(line);		
}*/
/*ctrl + tab = switch file on group in vscode
crtl + \(|) = open in new tab the duplicate file en cours
I like to move it - Madagascar (Roi Julian)*/
