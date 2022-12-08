/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:35:11 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/12/05 12:04:14 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_init(char **envp, t_data *data)
{
	data->code_exit = 0;
	data->readline = NULL;
	data->envp = NULL;
	data->nb_pipe = 0;
	data->token = NULL;
	data->tok_exe = NULL;
	data->fd_stdout = -1;
	data->fd_stdin = -1;
	data->last_fd = -1;
	ft_env(data, envp);
}

void	ft_reinit(t_data *data)
{
	data->nb_pipe = 0;
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
	}
	i = 0;
	while (envp[i] != NULL)
	{
		data->envp[i] = ft_strdup((const char *)envp[i]);
		i++;
	}
}

void	ft_print_env(t_data *data)
{
	int	i;

	i = 0;
	printf("ENVPPPPPPPPPPPPPPPPPPPPPP:\n");
	while (data->envp[i] != NULL)
	{
		ft_putstr_fd(data->envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
