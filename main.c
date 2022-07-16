/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:19:26 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/07/16 18:12:31 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char **arg, char **envp)
{
	while (1)
	{
		//printf("%s\n", readline("Minishell> "));
		readline("Minishell> ");
	}
}

int	main(int nb, char **arg, char **envp)
{
	if (nb != 1)
		printf("Error\n");
	else
	{
		//printf("%s\n", readline("Minishell: "));
		minishell(arg, envp);
	}
	return (0);
}
