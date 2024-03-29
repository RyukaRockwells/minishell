/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:35:11 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/12 13:02:31 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_init(char **envp, t_data *data)
{
	data->code_exit = 0;
	data->file_exit = 0;
	data->readline = NULL;
	data->envp = NULL;
	data->cmd_pipe = NULL;
	data->nb_pipe = 0;
	data->token = NULL;
	data->tok_exe = NULL;
	data->fd_in = -1;
	data->fd_out = -1;
	data->type_in = 0;
	data->type_out = 0;
	data->type_dout = 0;
	data->file_in = NULL;
	data->file_out = NULL;
	data->last_fd = -1;
	ft_env_init(data, envp);
}

void	ft_reinit(t_data *data)
{
	data->cmd_pipe = NULL;
	data->nb_pipe = 0;
	data->fd_in = -1;
	data->fd_out = -1;
	data->type_in = 0;
	data->type_out = 0;
	data->type_dout = 0;
	data->file_in = NULL;
	data->file_out = NULL;
	data->last_fd = -1;
	data->file_exit = 0;
	ft_free_all(data);
}

int	ft_env_nbline(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}

void	ft_env_init(t_data *data, char **envp)
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
	}
	i = 0;
	while (envp[i] != NULL)
	{
		data->envp[i] = ft_strdup((const char *)envp[i]);
		i++;
	}
}
