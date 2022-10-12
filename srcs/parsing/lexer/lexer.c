/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:40:06 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/05 13:05:31 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

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
		i += ft_get_word(data, i);
		i += ft_get_sep(data, i);
		i++;
	}
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
		if (ft_word_quote(str, i, str[i]) == 0)
		{
			ft_get_token(data, str, i, ft_wdlen(str, i));
			return (ft_wdlen(str, i));
		}
	}
	if (str[i] >= 33 && str[i] <= 126 && ft_check_metachar(str, i))
	{
		word = ft_substr(str, i, ft_wdlen(str, i));
		if (word == NULL)
			ft_exit(data);
		ft_add_token(word, data, LITERAL);
		return (ft_wdlen(str, i));
	}
	return (0);
}

int	ft_get_sep(t_data *data, int i)
{
	char	*sep;
	char	*str;

	str = data->readline;
	if (ft_is_space(str[i]) == 0)
		ft_add_space(data, str, i);
	if (str[i] == '<' || str[i] == '>')
	{
		ft_redirect(data, str, i);
		if (str[i] == str[i] && str[i + 1] == str[i])
			return (1);
	}
	if (str[i] == '|')
	{
		sep = ft_substr(str, i, 1);
		if (sep == NULL)
			ft_exit(data);
		ft_add_token(sep, data, PIPE);
	}
	return (0);
}

//recup le mot entre quotes
int	ft_word_quote(char *str, int i, char c)
{
	int		j;

	j = 0;
	while (str[i] != c)
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
