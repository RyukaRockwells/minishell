/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:06:11 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/06 20:06:19 by nicole           ###   ########.fr       */
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
		return (ft_free_gnl(&str));
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
	res = malloc(sizeof(char) * (ft_strlen_gnl(str) - i + 1));
	if (res == NULL)
		return (ft_free_gnl(&str));
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
	int		error_size;

	save = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!save)
		return (NULL);
	size = 1;
	while (ft_strchr_gnl(str) == 0 && size != 0)
	{
		size = read(fd, save, BUFFER_SIZE);
		error_size = check_size(size, save, str);
		if (error_size == 0)
			return (NULL);
		else if (error_size == 1)
			return ((char *)-1);
		save[size] = '\0';
		str = ft_strjoin_gnl(str, save);
		if (str == NULL)
			return (ft_free_gnl(&save));
	}
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	static	char	*(buff[1024]);
	char			*res;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
	{
		ft_free_gnl(&buff[0]);
		return (NULL);
	}
	buff[fd] = get_save(fd, buff[fd]);
	if (!buff[fd] || buff[fd] == (char *)-1)
		return (buff[fd]);
	res = get_line(buff[fd]);
	if (res == NULL)
		return (ft_free_gnl(&buff[fd]));
	buff[fd] = new_str(buff[fd]);
	if (buff[fd] == NULL)
		return (NULL);
	res[ft_strlen_gnl(res) - 1] = '\0';
	return (res);
}
