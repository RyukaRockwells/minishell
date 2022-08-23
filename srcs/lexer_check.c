/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:57:02 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/23 19:15:20 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_check_metachar(char *str, int i)
{
	if (ft_is_separator(str[i]) == 0 || ft_is_space(str[i]) == 0)
		return (1);
	return (0);
}

//J'aurais quel responsabilite? ou j'en aurais pas du tout
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
