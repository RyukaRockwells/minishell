/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:19:26 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/07/22 18:01:16 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_check(char *arg, char **envp)
{
	int		i;

	i = 0;
	while (arg != NULL)
	{
		/*if (ft_strcmp(arg[i], ">") == 0)
			ft_redirect(arg, i);
		else if (ft_strcmp(arg[i], "<") == 0)
			ft_redirect(arg, i);
		else if (ft_strcmp(arg[i], "|") == 0)
			ft_pipe(arg, i);*/
		i++;
	}
}

void	minishell(char **arg, char **envp)
{
	char	*line;

	ft_deco();
	while (1) //remplacer la boucle infini
	{
		line = readline("Minishell> ");
		if (ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			printf("Wesh\n");
			exit(EXIT_SUCCESS);
		}
		/*else if (ft_strncmp(line, NULL, ft_strlen(line)) == 0)
			printf("line = NULL\n");*/
		else
		{
			add_history(line);
			//ft_check(line, envp);
		}
	}
}

int	main(int nb, char **arg, char **envp)
{
	if (nb != 1)
		ft_error();
	else
		minishell(arg, envp);
	return (0);
}
