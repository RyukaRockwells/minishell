/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:11:04 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/05 14:36:01 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free_gnl(char **str)
{
	if (*str == NULL)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr_gnl(char *s)
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

int	check_size(int size, char *save, char *str)
{
	if (size == -1)
	{
		free(save);
		ft_free_gnl(&str);
		return (1);
	}
	else if (size == 0)
	{
		free(save);
		ft_free_gnl(&str);
		return (0);
	}
	return (-1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		len;

	dest = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (dest == NULL)
		return (ft_free_gnl(&s1));
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
