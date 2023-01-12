/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:55:58 by nicole            #+#    #+#             */
/*   Updated: 2023/01/12 19:00:28 by nchow-yu         ###   ########.fr       */
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

int	ft_exp_is_exist(t_data *data, char *str)
{
	char	*tmp;
	char	*env;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			break ;
		i++;
	}
	tmp = malloc(sizeof(char) * i + 1);
	if (tmp == NULL)
		ft_exit(1);
	ft_strlcpy(tmp, str, i + 1);
	env = ft_getenv(data, tmp);
	if (env == NULL)
	{
		free(tmp);
		return (1);
	}
	free(env);
	free(tmp);
	return (0);
}

char	*ft_getenv(t_data *data, char *str)
{
	int		i;
	char	*envp;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(str, data->envp[i], \
			ft_strlen_equal_var(data->envp[i])) != 0)
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
		ft_copy_single_quote(strexp, str, &i, &j);
		if (str[i] == '$')
		{
			i++;
			if (str[i] == '?')
				ft_expand_exit(data, strexp, &i, &j);
			else if (ft_exp_is_exist(data, str + i) != 0 && str[i] != '\0')
				i = ft_skip_name_var(str, i);
			else if (str[i] != '\0')
			{
				ft_replace_var_to_content(data, str + i, strexp, &j);
				i = ft_skip_name_var(str, i);
			}
		}
		else if (str[i] != '\0')
			strexp[j++] = str[i++];
	}
	strexp[j] = '\0';
}
