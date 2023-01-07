/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:54:56 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/07 18:37:32 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_strlen_name_var(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '=')
			break ;
		i++;
	}
	if (s[i] == '=')
		i++;
	return (i);
}

char	*ft_get_name_var(char *str)
{
	int		i;
	int		j;
	char	*name_var;

	i = 0;
	j = 0;
	name_var = malloc(sizeof(char) * ft_strlen_name_var(str) + 1);
	if (name_var == NULL)
		ft_exit(1);
	while (ft_isalnum(str[i]) == 1 || str[i] == '_')
	{
		if (str[i] == '=')
		{
			name_var[j++] = str[i];
			break ;
		}
		else
			name_var[j++] = str[i];
	}
	str[i] = '\0';
	return (name_var);
}

int	my_export(char **split_cmd, char **envp)
{
	char	*name_var;
	int		i;

	i = 0;
	(void)envp;
	if (split_cmd[1] == NULL)
	{
		fprintf(stderr, "minishell: export: pas d'argument\n");
		return (1);
	}
	name_var = ft_get_name_var(split_cmd[1]);
	return (0);
}
