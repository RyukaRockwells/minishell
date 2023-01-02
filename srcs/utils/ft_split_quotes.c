/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:26:35 by nicole            #+#    #+#             */
/*   Updated: 2023/01/02 20:28:53 by nicole           ###   ########.fr       */
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

static int	ft_nextmots(char *s, int pos, char c)
{
	int	i;

	i = pos;
	if (s == NULL)
		return (0);
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static int	ft_nbmots(char *s, char c)
{
	size_t	i;
	int		nbmots;

	i = 0;
	nbmots = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i])
			nbmots++;
		i = ft_pass_word(s, c, i);
		i++;
	}
	return (nbmots);
}

static char	**ft_assign(char const *s, char **res, int i, char c)
{
	int		a;
	int		b;
	int		len_m;

	a = 0;
	while (s[i] != '\0')
	{
		b = 0;
		len_m = ft_pass_word((char *)s, c, i);
		len_m = len_m - i;
		res[a] = malloc(sizeof(char) * len_m + 1);
		if (res[a] == NULL)
			return (ft_free_split(res));
		while (b < len_m && s[i] != 0)
		{
			if (s[i] == '\'')
			{
				i++;
				while (s[i] != '\'')
					res[a][b++] = s[i++];
				i++;
			}
			else if (s[i] == '\"')
			{
				i++;
				while (s[i] != '\"')
					res[a][b++] = s[i++];
				i++;
			}
			else
				res[a][b++] = s[i++];
		}
		res[a++][b] = 0;
		i = ft_nextmots((char *)s, i, c);
	}
	res[a] = NULL;
	return (res);
}

char	**ft_split_quote(char const *s, char c)
{
	int		i;
	char	**res;

	if (s == NULL)
		return (NULL);
	i = ft_nextmots((char *)s, 0, c);
	res = malloc(sizeof(char *) * (ft_nbmots((char *)s, c) + 1));
	if (res == NULL)
		return (NULL);
	return (ft_assign(s, res, i, c));
}
