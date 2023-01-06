/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:44:17 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 16:57:53 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	ft_replace_tab(t_data *data, int *i, int size)
{
	if ((*i) < size - 1)
	{
		while (data->envp[(*i) + 1] != NULL)
		{
			data->envp[(*i)] = data->envp[(*i) + 1];
			(*i)++;
		}
	}
	data->envp[(*i)] = NULL;
}

int	ft_unset(t_data *data, char **var, int size)
{
	int	i;

	i = 0;
	size = ft_tablen(data->envp);
	if (ft_tablen(var) < 2)
	{
		ft_putstr_fd("unset: not enough arguments\n", 2);
		ft_free_tab(var);
		return (1);
	}
	var[1] = ft_strjoin(var[1], "=");
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(data->envp[i], var[1], ft_strlen(var[1])) == 0)
		{
			free(data->envp[i]);
			data->envp[i] = NULL;
			ft_replace_tab(data, &i, size);
			ft_free_tab(var);
			return (0);
		}
		i++;
	}
	return (0);
}
