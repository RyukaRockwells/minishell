/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:15:21 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/18 14:11:57 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	**ft_free(char **tab);
char	**ft_split(char const *s, char c);

int	main(void)
{
	char	*line;
	char	**rslt;

	line = "echo -n -n";
	printf("deb split:\n");
	rslt = ft_split((char const *)line, ' ');
	if (rslt == NULL)
		return (1);
	printf("%s\n", rslt[0]);
	printf("%s\n", rslt[1]);
	ft_free(rslt);
}
