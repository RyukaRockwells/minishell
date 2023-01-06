/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:14:58 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 12:26:22 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_check_for_empty(char *str, int i)
{
	char	*s;

	s = ft_strdup(str);
	while (s[i] != '\0')
	{
		if (s[i] == '\"')
		{
			s[i++] = ' ';
			while (s[i] != '\"')
				i++;
			s[i++] = ' ';
		}
		else if (s[i] == '\'')
		{
			s[i++] = ' ';
			while (s[i] != '\'')
				i++;
			s[i++] = ' ';
		}
		else
			i++;
	}
	return (s);
}

int	ft_cmd_is_empty(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (0);
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
			{
				if (ft_is_space(str[i]) == 1)
					i++;
				else
					return (0);
				i++;
			}
			i++;
		}
		i++;
	}
	return (1);
}

int	ft_empty_tok(t_token *tok)
{
	while (tok != NULL)
	{
		if (tok->type != ESPACE)
			return (1);
		tok = tok->next;
	}
	return (0);
}
