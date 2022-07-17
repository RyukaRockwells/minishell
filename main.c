/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:19:26 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/07/17 20:24:47 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char **arg, char **envp)
{
	char	*line;

	while (1)
	{
		line = readline("Minishell> ");
		if (line == "exit")
		{
			printf("Wesh\n");
			exit(EXIT_SUCCESS);
		}//printf("%s\n", readline("Minishell> "));
		else if (line == "gt")
			printf("%s\n", "Je suis un gros toutou");
		else
			add_history(line);
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
