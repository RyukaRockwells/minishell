/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:36:55 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/06/04 20:52:43 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_line(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * i + 2);
	if (res == NULL)
		return (gnl_free(&str));
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*new_str(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (gnl_strlen(str) - i + 1));
	if (res == NULL)
		return (gnl_free(&str));
	if (str[i] == '\n')
		i++;
	while (str[i] != '\0')
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*get_save(int fd, char *str)
{
	char				*save;
	long long int		size;

	save = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (save == NULL)
		return (NULL);
	size = 1;
	while (ft_strline(str) == 0 && size != 0)
	{
		size = read(fd, save, BUFFER_SIZE);
		if (size == -1)
		{
			free(save);
			return (gnl_free(&str));
		}
		save[size] = '\0';
		str = ft_gnljoin(str, save);
		if (str == NULL)
			return (gnl_free(&save));
	}
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff);
		return (NULL);
	}
	buff = get_save(fd, buff);
	if (buff == NULL)
		return (NULL);
	res = get_line(buff);
	if (res == NULL)
		return (gnl_free(&buff));
	buff = new_str(buff);
	if (buff == NULL)
		return (NULL);
	return (res);
}
