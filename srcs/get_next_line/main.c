/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:24:30 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/02/03 15:38:55 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

/*int	main(void)
{
	char	*str;
	int		fd;

	str = "1";
	fd = 0;
	//fd = open("test.txt", O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	close (fd);
	return (0);
}*/

int	main(int ac, char **av)
{
	char	*str;
	int		fd;
	//int		fd1;

	str = "1";
	fd = open(av[1], O_RDONLY);
	//fd1 = open(av[2], O_RDONLY);
	(void)ac;
	/*
	str = get_next_line(0);
	printf("%s", str);
	free(str);
	
	str = get_next_line(0);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	*/
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	close (fd);
	return (0);
}
