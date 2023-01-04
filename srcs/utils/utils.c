/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:19:52 by nicole            #+#    #+#             */
/*   Updated: 2023/01/04 23:33:33 by nicole           ###   ########.fr       */
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

int	ft_pass_word(char *s, char c, int i)
{
	while (s[i] != '\0' && s[i] != c)
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'')
				i++;
		}
		else if (s[i] == '\"')
		{
			i++;
			while (s[i] != '\"')
				i++;
		}
		i++;
	}
	return (i);
}

int	ft_len_word(char *s, char c, int i)
{
	int	quote;

	quote = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		if (s[i] == '\'')
		{
			quote = 1;
			i++;
			while (s[i] != '\'')
				i++;
		}
		else if (s[i] == '\"')
		{
			quote = 1;
			i++;
			while (s[i] != '\"')
				i++;
		}
		i++;
	}
	if (quote == 1)
		i -= 2;
	return (i);
}

char	*ft_copy_in_tab(char *res, char *s, int *j_res, int *i)
{
	if (s[(*i)] == '\'')
	{
		(*i)++;
		while (s[(*i)] != '\'')
			res[(*j_res)++] = s[(*i)++];
		(*i)++;
	}
	else if (s[(*i)] == '\"')
	{
		(*i)++;
		while (s[(*i)] != '\"')
			res[(*j_res)++] = s[(*i)++];
		(*i)++;
	}
	else
		res[(*j_res)++] = s[(*i)++];
	return (res);
}
