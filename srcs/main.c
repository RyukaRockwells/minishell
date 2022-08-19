/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:19:26 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/19 19:00:40 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/*
void	ft_check(char *arg, char **envp)
{
	int		i;

	i = 0;
	while (arg != NULL)
	{
		if (ft_strcmp(arg[i], ">") == 0)
			ft_redirect(arg, i);
		else if (ft_strcmp(arg[i], "<") == 0)
			ft_redirect(arg, i);
		else if (ft_strcmp(arg[i], "|") == 0)
			ft_pipe(arg, i);
		i++;
	}
}

void	ft_redirect(char *arg, int i)
{
	if (arg[i + 1] == '>')
		ft_redirect_out(arg, i);
	else if (arg[i + 1] == '<')
		ft_redirect_in(arg, i);
}

void	minishell(char **arg, char **envp)
{
	char	*line;

	ft_deco();
	printf("arg: %s\n", arg[0]);
	printf("envp: %s\n", envp[0]);
	while (1) //remplacer la boucle infini
	{
		line = readline("Minishell> ");
		if (ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			printf("Wesh\n");
			exit(EXIT_SUCCESS);
		}
		else if (ft_strncmp(line, NULL, ft_strlen(line)) == 0)
			printf("line = NULL\n");
		else
		{
			add_history(line);
			ft_check(line, envp);
		}
	}
}
*/

void	ft_check(char *line)
{
	char	**args;
	int		i;

	args = ft_split(line, ' ');
	i = 0;
	if (args == NULL)
		return ;
	while (args[i] != NULL)
		printf("args: %s\n", args[i++]);
}

int	main(int nb, char **arg, char **envp)
{
	t_data data;

	(void)arg;
	if (nb != 1)
		ft_error();
	ft_init(envp, &data);
	ft_loop(&data);
	return (0);
}
