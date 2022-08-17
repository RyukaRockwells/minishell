/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:15:21 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/17 19:43:59 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char	*line;
	char	**rslt;

	line = "echo '-n -n'";
	rslt = ft_split(line, ' ');
	if (rslt == NULL)
		return (1);
	printf("%s\n", rslt[0]);
	printf("%s\n", rslt[1]);
	ft_free(rslt);
}
