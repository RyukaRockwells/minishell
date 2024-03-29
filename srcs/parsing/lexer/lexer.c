/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:40:06 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/10 16:25:20 by nchow-yu         ###   ########.fr       */
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
	while (i < (int)ft_strlen(data->readline))
	{
		i += ft_get_word(data, i);
		i += ft_get_sep(data, i);
		i++;
	}
	return (0);
}

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
			ft_exit(1);
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
		if (str[i + 1] == str[i])
			return (1);
	}
	if (str[i] == '|')
	{
		sep = ft_substr(str, i, 1);
		if (sep == NULL)
			ft_exit(1);
		ft_add_token(sep, data, PIPE);
	}
	return (0);
}

int	ft_len_word_quote(char *str, int i, char c)
{
	int	quote;
	int	length;

	quote = 0;
	length = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		if (str[i] == quote)
			quote = 0;
		else if (str[i] == '\'' && str[i] == '\"' && quote == 0)
			quote = str[i];
		else if (quote != 0)
			length++;
		else if (ft_isascii(str[i]) == 1 && quote == 0)
			length++;
		i++;
	}
	return (length);
}

int	ft_word_quote(char *str, int i, char c)
{
	char	quote;

	quote = str[i];
	while (i < ft_len_word_quote(str, i, c))
	{
		if (str[i] == quote)
			quote = 0;
		else if ((str[i] == '\'' || str[i] == '\"') && quote == 0)
			quote = str[i];
		i++;
	}
	if (str[i] != c)
		return (1);
	return (0);
}
