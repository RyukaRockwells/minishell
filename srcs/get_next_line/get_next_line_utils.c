/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:37:49 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/06/04 20:54:52 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_free(char **str)
{
	if (*str == NULL)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_gnljoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		len;

	dest = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (dest == NULL)
		return (gnl_free(&s1));
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2 != NULL && s2[len] != '\0')
	{
		dest[i] = s2[len];
		i++;
		len++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}
