/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:35:45 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 16:40:05 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**ft_free_split(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

char	*ft_copy_in_str_split(char *str_split, char *s, int len_word, int i_s)
{
	char	quote;
	int		j;

	quote = 0;
	j = 0;
	while (j < len_word)
	{
		if (s[i_s] == quote)
			quote = 0;
		else if ((s[i_s] == '\'' || s[i_s] == '\"') && quote == 0)
			quote = s[i_s];
		else
			str_split[j++] = s[i_s];
		i_s++;
	}
	str_split[j] = '\0';
	return (str_split);
}

int	ft_nextword(char *s, char sep, int i_s)
{
	char	quote;
	int		meet_space;

	quote = 0;
	meet_space = 0;
	while (s[i_s] != '\0')
	{
		if (s[i_s] == quote)
			quote = 0;
		else if (s[i_s] == '\'' || s[i_s] == '\"')
			quote = s[i_s];
		else if (s[i_s] == sep && quote == 0)
			meet_space = 1;
		if (s[i_s] != sep && meet_space == 1)
			return (i_s);
		i_s++;
	}
	return (i_s);
}

char	**ft_assign_for_split(char *s, char **str_split, int i_s, char sep)
{
	int		i;
	int		len_word;

	i = 0;
	while (s[i_s] != '\0')
	{
		len_word = ft_strlen_word(s, sep, i_s) - i_s;
		str_split[i] = malloc(sizeof(char) * len_word + 1);
		if (str_split[i] == NULL)
			return (ft_free_split(str_split));
		str_split[i] = ft_copy_in_str_split(str_split[i], s, len_word, i_s);
		i++;
		i_s = ft_nextword(s, sep, i_s);
	}
	str_split[i] = NULL;
	return (str_split);
}

char	**ft_split_quote(char *s, char sep)
{
	int		i_s;
	char	**str_split;

	i_s = 0;
	if (s == NULL || ft_nbword(s, sep) == 0)
		return (NULL);
	while (s[i_s] == sep && s[i_s] != '\0')
		i_s++;
	str_split = malloc(sizeof(char *) * (ft_nbword(s, sep) + 1));
	if (str_split == NULL)
		return (NULL);
	str_split = ft_assign_for_split(s, str_split, i_s, sep);
	return (str_split);
}
