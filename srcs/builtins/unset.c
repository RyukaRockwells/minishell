/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:26:49 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/08 19:14:13 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_unset_var(char *var_unset, t_data *data)
{
	int		i;
	int		j;
	char	**envp;

	i = 0;
	j = 0;
	envp = malloc(sizeof(char *) * (ft_env_nbline(data->envp) + 1));
	if (envp == NULL)
		ft_exit(1);
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(data->envp[i], var_unset, ft_strlen(var_unset)) == 0)
			i++;
		else
			envp[j++] = ft_strdup(data->envp[i++]);
	}
	envp[j] = NULL;
	ft_free_tab(data->envp);
	data->envp = envp;
}

int	ft_unset(t_data *data, char **split_cmd)
{
	int		i;
	char	*var_unset;

	i = 1;
	if (split_cmd[1] == NULL)
	{
		ft_putstr_fd("unset: not enough arguments\n", 2);
		return (1);
	}
	while (split_cmd[i] != NULL)
	{
		var_unset = ft_strjoin(split_cmd[i], "=");
		ft_unset_var(var_unset, data);
		free(var_unset);
		i++;
	}
	return (1);
}
