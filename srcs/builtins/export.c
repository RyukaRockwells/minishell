/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:49:02 by nicole            #+#    #+#             */
/*   Updated: 2023/01/07 17:53:50 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_export2(char *var, char *str, char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) == 0)
		{
			free(envp[i]);
			envp[i] = ft_strdup(str);
			return (envp);
		}
		i++;
	}
	envp[i] = ft_strdup(str);
	return (envp);
}

int	ft_nb_equals(char *arg)
{
	int	i;
	int	equals;

	i = 0;
	equals = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '=')
			equals++;
		i++;
	}
	if (equals == 1)
		return (1);
	else if (equals > 1)
	{
		ft_putstr_fd("minishell: export: must be one equal\n", 2);
		return (2);
	}
	else if (equals < 1)
		return (0);
	return (0);
}

char	*ft_get_key(char *arg)
{
	int		i;
	char	*key;

	i = 0;
	while (arg[i] != '=' && arg[i] != '\0')
		i++;
	key = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (arg[i] != '=' && arg[i] != '\0')
	{
		key[i] = arg[i];
		i++;
	}
	key[i] = '=';
	key[i + 1] = '\0';
	return (key);
}

int	ft_key_is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[0] >= '0' && str[0] <= '9')
		return (1);
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 1 || str[i] == '_' || str[i] == '=')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_export(char **args, char **envp)
{
	char	*key;
	int		equals;
	int		i;

	i = ft_tablen(args);
	if (i < 2)
		return (1);
	equals = ft_nb_equals(args[1]);
	if (equals == 0)
		return (1);
	key = ft_get_key(args[1]);
	if (ft_key_is_valid(key) != 0)
	{
		ft_putstr_fd("minishell: export: not an identifier\n", 2);
		free(key);
		return (1);
	}
	ft_export2(key, args[1], envp);
	free(key);
	return (1);
}
