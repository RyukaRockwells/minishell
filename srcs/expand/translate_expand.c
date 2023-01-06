/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:55:58 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 13:13:42 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_copy_double_quotes(char *strexp, char *str, int *i, int *j)
{
	if (str[(*i)] == '\"')
	{
		strexp[(*j)++] = str[(*i)++];
		while (str[(*i)] != '\"')
		{
			if (str[(*i)] == '$')
			{
				if (str[(*i)++] == '?')
					return (0);
				else if (ft_exp_is_exist(str + (*i)) != 0)
					while (ft_isalnum(str[(*i)]) == 1 || str[(*i)] == '_')
						(*i)++;
				else
					ft_replace_var_to_content(str, strexp, &(*i), &(*j));
			}
			else if (str[(*i)] == '\0')
				break ;
			else
				strexp[(*j)++] = str[(*i)++];
		}
		strexp[(*j)++] = str[(*i)++];
	}
	return (1);
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
		if (ft_copy_double_quotes(strexp, str, &i, &j) == 0)
			ft_expand_exit(data, strexp, &i, &j);
		else if (str[i] == '$')
		{
			i++;
			if (str[i] == '?')
				ft_expand_exit(data, strexp, &i, &j);
			else if (ft_exp_is_exist(str + i) != 0)
				while (ft_isalnum(str[i]) == 1 || str[i] == '_')
					i++;
			else
				ft_replace_var_to_content(str, strexp, &i, &j);
		}
		else if (str[i] == '\0')
			break ;
		else
			strexp[j++] = str[i++];
	}
	strexp[j] = '\0';
}
