/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:40:06 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/23 12:14:28 by nchow-yu         ###   ########.fr       */
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
		index += ft_get_word(data->readline, i);
		//index += ft_get_quote(data->readline, i);
		//index += ft_get_separators(data, i);
		index++;
	}
	return (0);
}

int	ft_parser(t_data *data)
{
	return (0);
}

int	ft_get_word(t_data data->readline, int i)
{
	char	*word;
	char	*str;

	str = data->readline;
	if (str[i] == 39 || str[i] == 34)
		if (ft_word_quote(str, i) == 0)
		{
			return (0);
		}
}

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

int	ft_get_separators(t_data data->readline, int i)
{

}

int	ft_get_quote(t_data data->readline, int i)
{

}

void	ft_add_token()

void	ft_print_tokenssss()
