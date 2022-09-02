/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:40:06 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/02 13:28:34 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_lexer(t_data *data)
{
	int	i;
	int	status;

	status = ft_check_quotes(data->readline);
	if (status > 0)
		return (QUOTES_NO_CLOSE);
	i = 0;
	while (i < ft_strlen(data->readline))
	{
		if (ft_is_space(data->readline[i]))
			i++;
		i += ft_get_word(data, i);
		//index += ft_get_quote(data->readline, i);
		//index += ft_get_separators(data, i);
		i++;
	}
	show_token(data);
	return (0);
}

int	ft_parser(t_data *data)
{
	return (0);
}
//!!!revoir le fonctionnement de ft_wdlen!!!

int	ft_get_word(t_data *data, int i)
{
	char	*word;
	char	*str;

	str = data->readline;
	if (str[i] == 39 || str[i] == 34)
	{
		if (ft_word_quote(str, i) == 0)
		{
			ft_get_token(data, str, i, ft_wdlen(str, i));
			return (ft_wdlen(str, i));
		}
	}
	if (str[i] >= 33 && str[i] <= 126 && ft_check_metachar(str, i))
	{
		word = ft_substr(str, i, ft_wdlen(str, i));
		if (word == NULL)
			ft_exit(data); /*free(word);*/
		ft_add_token(word, data, LITERAL);
		return (ft_wdlen(str, i));
	}
	return (0);
}

//recup le mot entre quotes
int	ft_word_quote(char *str, int i)
{
	int		j;

	j = 0;
	while (str[i] != 39 || str[i] != 34)
	{	
		i++;
		j++;
	}
	if (str[i + 1] == '\0')
		return (0);
	else if (ft_check_metachar(str, i + 1) == 0)
		return (1);
	else
		return (0);
}
/*
int	ft_get_separators(t_data data->readline, int i)
{

}

int	ft_get_quote(t_data data->readline, int i)
{

}

void	ft_add_token()

void	ft_print_tokenssss()
*/
