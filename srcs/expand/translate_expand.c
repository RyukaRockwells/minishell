/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:55:58 by nicole            #+#    #+#             */
/*   Updated: 2023/01/07 15:48:34 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_copy_env(char *content_env, char *envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i] != '=')
		i++;
	i++;
	while (envp[i] != '\0')
		content_env[j++] = envp[i++];
	content_env[j] = '\0';
	return (content_env);
}

char	*ft_getenv(t_data *data, char *str)
{
	int		i;
	int		j;
	char	*envp;

	i = 0;
	j = 0;
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(str, data->envp[i], ft_strlen(str)) != 0)
			i++;
		else
			break ;
	}
	if (data->envp[i] == NULL)
		return (NULL);
	envp = malloc(sizeof(char) * ft_strlen_contents_var(data->envp[i]) + 1);
	if (envp == NULL)
		ft_exit(1);
	envp = ft_copy_env(envp, data->envp[i]);
	return (envp);
}

void	ft_translate_expand(t_data *data, char *str, char *strexp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
		{
			strexp[j++] = str[i++];
			while (str[i] != '\'')
				strexp[j++] = str[i++];
			strexp[j++] = str[i++];
		}
		else if (str[i] == '$')
		{
			if (str[++i] == '?')
				ft_expand_exit(data, strexp, &i, &j);
			else if (ft_exp_is_exist(data, str + i) != 0)
				i = ft_skip_name_var(str, i);
			else
			{
				ft_replace_var_to_content(data, str + i, strexp, &j);
				i = ft_skip_name_var(str, i);
			}
		}
		else
			strexp[j++] = str[i++];
	}
	strexp[j] = '\0';
}
