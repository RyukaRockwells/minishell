/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:28:10 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 23:42:08 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_replace_var_to_content(char *str, char *strexp, int	*i, int *j)
{
	int		k;
	int		start_env;
	char	*env;
	char	char_save;

	k = 0;
	env = "";
	start_env = (*i);
	while (str[(*i)] != '\0')
	{
		while (ft_isalnum(str[(*i)]) == 1 || str[(*i)] == '_')
			(*i)++;
		break ;
	}
	char_save = str[(*i)];
	str[(*i)] = '\0';
	env = getenv(str + start_env);
	str[(*i)] = char_save;
	while (env[k] != '\0')
	{
		strexp[(*j)] = env[k];
		(*j)++;
		k++;
	}
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

int	ft_exp_is_exist(char *str)
{
	char	*tmp;
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
	if (getenv(tmp) == NULL)
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}
