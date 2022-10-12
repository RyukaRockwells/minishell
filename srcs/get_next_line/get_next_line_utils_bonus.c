/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linus_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:11:04 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/02/01 16:13:18 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	if (*str == NULL)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		len;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (ft_free(&s1));
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
