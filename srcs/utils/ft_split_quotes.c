/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:26:35 by nicole            #+#    #+#             */
/*   Updated: 2023/01/04 19:45:30 by nicole           ###   ########.fr       */
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
	int		i_res;
	int		j_res;
	int		len_m;

	i_res = 0;
	while (s[i] != '\0')
	{
		j_res = 0;
		len_m = ft_len_word((char *)s, c, i);
		len_m = len_m - i;
		res[i_res] = malloc(sizeof(char) * len_m + 1);
		if (res[i_res] == NULL)
			return (ft_free_split(res));
		while (j_res < len_m && s[i] != 0)
		{
			res[i_res] = ft_copy_in_tab(res[i_res], (char *)s, &j_res, &i);
		}
		res[i_res++][j_res] = 0;
		i = ft_nextmots((char *)s, i, c);
	}
	res[i_res] = NULL;
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
