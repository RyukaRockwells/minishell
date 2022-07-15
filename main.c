/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:19:26 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/07/13 12:34:58 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(int nb, char **arg)
{
	if (nb != 1)
		printf("Error\n");
	else
	{
		printf("%s\n", readline("Minishell: "));
	}
	return (0);
}
