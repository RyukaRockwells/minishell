/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:28:10 by nicole            #+#    #+#             */
/*   Updated: 2023/01/07 15:41:29 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_replace_var_to_content(t_data *data, char *str, char *exp, int *j)
{
	int		i;
	int		k;
	char	*env;
	char	char_save;

	k = 0;
	i = ft_skip_name_var(str, 0);
	while (str[i] != '\0')
	{
		while (ft_isalnum(str[i]) == 1 || str[i] == '_')
			i++;
		break ;
	}
	char_save = str[i];
	str[i] = '\0';
	env = ft_getenv(data, str);
	str[i] = char_save;
	while (env[k] != '\0')
	{
		exp[(*j)] = env[k];
		(*j)++;
		k++;
	}
	free(env);
}

void	ft_copy_single_quote(char *strexp, char *str, int *i, int *j)
{
	if (str[(*i)] == '\'')
	{
		strexp[(*j)++] = str[(*i)++];
		while (str[(*i)] != '\'')
			strexp[(*j)++] = str[(*i)++];
		strexp[(*j)++] = str[(*i)++];
	}
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
