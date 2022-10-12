/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:06:11 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/02/02 12:44:02 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (ft_free(&str));
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
	res = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (res == NULL)
		return (ft_free(&str));
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
	char	*save;
	int		size;

	save = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!save)
		return (NULL);
	size = 1;
	while (ft_strchr(str) == 0 && size != 0)
	{
		size = read(fd, save, BUFFER_SIZE);
		if (size == -1)
		{
			free(save);
			return (ft_free(&str));
		}
		save[size] = '\0';
		str = ft_strjoin(str, save);
		if (str == NULL)
			return (ft_free(&save));
	}
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	static	char	*(buff[1024]);
	char			*res;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = get_save(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	res = get_line(buff[fd]);
	if (res == NULL)
		return (ft_free(&buff[fd]));
	buff[fd] = new_str(buff[fd]);
	if (buff[fd] == NULL)
		return (NULL);
	return (res);
}
