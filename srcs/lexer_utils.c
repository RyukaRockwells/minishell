/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:53:35 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/19 17:31:00 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' 
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_is_separator(char c)
{
	if (c == ';' || c == '|' || c == '&' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	ft_check_quotes(char *str)
{
	int		i;
	int		quotes;

	i = 0;
	quotes = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
		{
			if (quotes == 0)
				quotes = S_QUOTES;
			else if (quotes == S_QUOTES)
				quotes = 0;
		}
		else if (str[i] == '\"')
		{
			if (quotes == 0)
				quotes = D_QUOTES;
			else if (quotes == D_QUOTES)
				quotes = 0;
		}
		i++;
	}
	return (quotes);
}
