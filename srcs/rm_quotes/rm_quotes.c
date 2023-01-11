/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:46:06 by nicole            #+#    #+#             */
/*   Updated: 2023/01/11 14:53:28 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_length_str_without_quotes(char *str)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			i++;
		else
		{
			length++;
			i++;
		}
	}
	return (length);
}

int	ft_strlen_before_hd(char *str)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (str[i] != '\0')
	{
		if (str[i] == quote)
			quote = 0;
		else if (str[i] == '\'' && str[i] == '\"' && quote == 0)
			quote = str[i];
		else if (str[i] == '<' && str[i + 1] == '<' && quote == 0)
			return (i);
		i++;
	}
	return (i);
}

int	ft_strlen_after_hd(char *str)
{
	int	i;
	int	length;
	int	quote;

	i = ft_strlen_before_hd(str) + 2;
	length = 2;
	quote = 0;
	while (ft_is_space(str[i]) == 0 && str[i] != '\0')
		i++;
	while (str[i] != '\0')
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

char	*ft_rm_heredoc_in_str(char *str)
{
	int		i;
	int		j;
	int		start;
	int		end;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	start = ft_strlen_before_hd(str);
	end = ft_strlen_after_hd(str);
	while (str[i] != '\0')
	{
		if (i >= start && i <= end)
			new_str[j] = ' ';
		else
		{
			new_str[j] = str[i];
		}
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
