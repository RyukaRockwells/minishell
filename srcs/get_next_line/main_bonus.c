/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:12:42 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/02/03 15:13:32 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*str;
	int		fd;
	int		fd1;

	str = "1";
	fd = open(av[1], O_RDONLY);
	fd1 = open(av[2], O_RDONLY);
	(void)ac;
	
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd);
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
	
	close (fd);
	close(fd1);
	return (0);
}