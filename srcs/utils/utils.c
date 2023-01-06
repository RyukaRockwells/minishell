/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:19:52 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 23:09:00 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strcpy(char *dest, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_nbword(char *s, char sep)
{
	char	quote;
	int		nbword;
	int		i;
	int		meet_space;

	quote = 0;
	nbword = 0;
	i = 0;
	meet_space = 1;
	while (s[i] != '\0')
	{
		if (s[i] == quote)
			quote = 0;
		else if (s[i] == '\'' || s[i] == '\"')
			quote = s[i];
		else if (s[i] == sep && quote == 0)
			meet_space = 1;
		if (s[i] != sep && meet_space == 1)
		{
			meet_space = 0;
			nbword++;
		}
		i++;
	}
	return (nbword);
}

int	ft_strlen_word(char *s, char sep, int i_s)
{
	int	quote;

	quote = 0;
	while (s[i_s] != '\0' && s[i_s] != sep)
	{
		if (s[i_s] == '\'')
		{
			quote++;
			i_s++;
			while (s[i_s] != '\'')
				i_s++;
		}
		if (s[i_s] == '\"')
		{
			quote++;
			i_s++;
			while (s[i_s] != '\"')
				i_s++;
		}
		i_s++;
	}
	if (quote != 0)
		i_s -= (quote * 2);
	return (i_s);
}
