/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:26:49 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/10 17:11:50 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	key = malloc(sizeof(char *) * (i + 1));
	if (!key)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '=')
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

void	ft_unset_var(char *var_unset, t_data *data)
{
	int		i;
	int		j;
	char	**envp;
	char	*key;

	i = 0;
	j = 0;
	envp = malloc(sizeof(char *) * (ft_env_nbline(data->envp) + 1));
	if (envp == NULL)
		ft_exit(1);
	while (data->envp[i] != NULL)
	{
		key = get_key(data->envp[i]);
		if (ft_strncmp(key, var_unset, ft_strlen(var_unset)) == 0
			&& ft_strlen(key) == ft_strlen(var_unset))
			i++;
		else
			envp[j++] = ft_strdup(data->envp[i++]);
		free (key);
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
	var_unset = NULL;
	if (split_cmd[1] == NULL)
	{
		ft_putstr_fd("unset: not enough arguments\n", 2);
		return (1);
	}
	while (split_cmd[i] != NULL)
	{
		var_unset = split_cmd[i];
		ft_unset_var(var_unset, data);
		i++;
	}
	return (1);
}
