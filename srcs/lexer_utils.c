/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:53:35 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/23 13:34:33 by nchow-yu         ###   ########.fr       */
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
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	ft_check_metachar(char *str, int i)
{
	if (ft_is_separator(str[i]) || ft_is_space(str[i]))
		return (1);
	return (0);
}
//regarder dans lexer_utils.c pour la fonction ft_word_len

int	ft_wdlen(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] != '\0')
	{
		if (ft_check_metachar(str, i) == 1)
			return (i);
		else if (str[i++] == 34)
		{
			j++;
			while (str[i++] != 34)
				j++;
		}
	}
}

int	ft_check_quotes(char *str)
{
	int		i;
	int		quotes;

	i = -1;
	quotes = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == 39)
		{
			if (quotes == 0)
				quotes = S_QUOTES;
			else if (quotes == S_QUOTES)
				quotes = 0;
		}
		else if (str[i] == 34)
		{
			if (quotes == 0)
				quotes = D_QUOTES;
			else if (quotes == D_QUOTES)
				quotes = 0;
		}
	}
	return (quotes);
}
