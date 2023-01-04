/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:49:02 by nicole            #+#    #+#             */
/*   Updated: 2023/01/04 23:57:36 by nicole           ###   ########.fr       */
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

int	ft_key_is_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			i++;
		else if (str[0] == '_')
			return (0);
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
	printf("I ===== %d\n", i);
	printf("ARGS[1] ==== %s\n", args[1]);
	if (i < 2)
		return (1);
	equals = ft_nb_equals(args[1]);
	key = ft_get_key(args[1]);
	if (equals == 0)
		args[1] = key;
	printf("key: %s\n", key);
	if (ft_key_is_upper(key) == 0)
		printf("key2: %s\n", key);
	else
	{
		ft_putstr_fd("minishell: export: not an identifier\n", 2);
		return (1);
	}
	ft_export2(key, args[1], envp);
	free(key);
	return (1);
}
