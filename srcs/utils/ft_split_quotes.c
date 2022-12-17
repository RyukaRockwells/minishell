/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:26:35 by nicole            #+#    #+#             */
/*   Updated: 2022/12/17 18:04:50 by nicole           ###   ########.fr       */
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
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'')
				i++;
			break ;
		}
		else if (s[i] == '\"')
		{
			i++;
			while (s[i] != '\"')
				i++;
			break ;
		}
		else if (s[i] == c)
			break ;
		i++;
	}
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
		while (s[i] != '\0')
		{
			if (s[i] == '\'')
			{
				i++;
				while (s[i] != '\'')
					i++;
				break ;
			}
			else if (s[i] == '\"')
			{
				i++;
				while (s[i] != '\"')
					i++;
				break ;
			}
			else if (s[i] == c)
				break ;
			i++;
		}
		if (s[i])
			nbmots++;
		while (s[i] != '\0')
		{
			if (s[i] == '\'')
			{
				i++;
				while (s[i] != '\'')
					i++;
				break ;
			}
			else if (s[i] == '\"')
			{
				i++;
				while (s[i] != '\"')
					i++;
				break ;
			}
			else if (s[i] == c)
				break ;
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
		while (s[len_m] != c && s[len_m] != '\0')
			len_m++;
		len_m = len_m - i;
		res[a] = malloc(sizeof(char) * len_m + 1);
		if (res[a] == NULL)
			return (ft_free_split(res));
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

int	main(void)
{
	char	**str;
	int		i;

	//fprintf(stderr, "nextmots = %d\n", ft_nextmots("bonjour    \'\"\'", 0, ' '));
	//fprintf(stderr, "nextmots = %d\n", ft_nextmots("bonjour    \'\"\'", 11, ' '));
	fprintf(stderr, "bonjour \"Un peu beauuu  coup\"");
	str = ft_split("bonjour \"Un peu beauuu  coup\"", ' ');
	write(2, "\n", 1);
	i = 0;
	while (str[i] != NULL)
	{
		fprintf(stderr, "str after split: %s\n", str[i]);
		i++;
	}
}
