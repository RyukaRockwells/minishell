/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:21:07 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/17 19:48:38 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **tab)
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
	while (s[i] == c && s[i] != '\0' && s[i] == '"' && s[i] == '\'')
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
		while (s[i] == c && s[i] != '\0' )//&& s[i] == '"' && s[i] == '\'')
		{
			i++;
		}
		if (s[i])
			nbmots++;
		while (s[i] != c && s[i] != '\0')// && s[i] != '"' && s[i] != '\'')
		{
			i++;
		}
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
		len_m = i;
		while (s[len_m] != c && s[len_m] != '\0' )//&& s[len_m] != '"' && s[len_m] != '\'')
			len_m++;
		len_m = len_m - i;
		res[a] = malloc(sizeof(char) * len_m + 1);
		if (res[a] == NULL)
			return (ft_free(res));
		while (b < len_m && s[i] != 0)
			res[a][b++] = s[i++];
		res[a++][b] = 0;
		i = ft_nextmots((char *)s, i, c);
	}
	res[a] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
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
