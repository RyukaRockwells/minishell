/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:53:35 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/02 18:17:47 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (0);
	return (1);
}

int	ft_is_separator(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (0);
	return (1);
}

//regarder dans lexer_utils.c pour la fonction ft_word_len
//2e boucle if => fonctionnement bizarre
//metachar != mot, si fin est \0 on sort

int	ft_is_word_util(char *read_line, int index, int len)
{
	if (ft_check_metachar(read_line, index))
	{
		if (read_line[index] == '\0')
			return (len);
	}
	return (0);
}

int	ft_wdlen(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] != '\0')
	{
		if (ft_check_metachar(str, i) == 1)
			return (j);
		if (str[i++] == 34)
		{
			j++;
			i++;
			while (str[i] != 34)
			{
				i++;
				j++;
			}
		}
		if (ft_is_word_util(str, i, j) == 1)
			return (j);
	}
	printf("j: %d\n", j);//a enlever
	return (j);
}
