/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:35:11 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/17 19:02:38 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_init(char **envp, t_list *list)
{
	list->code_exit = 0;
	list->readline = NULL;
	list->envp = NULL;
	list->nb_process = 0;
	list->token = NULL;
	list->fd_stdout = -1;
	list->fd_stdin = -1;
	ft_env(list, envp);
}

int	ft_env_nbline(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}

void	ft_env(t_list *list, char **envp)
{
	int		i;

	i = 0;
	list->envp = malloc(sizeof(char *) * (ft_env_nbline(envp) + 1));
	if (list->envp == NULL)
		ft_error("malloc error");
	while (envp[i] != NULL)
	{
		list->envp[i] = ft_strdup(envp[i]);
		i++;
	}//boucle while false
}
/*char	*line;

ft_deco();
while (1)
{
	line = readline("Minishell> ");
	add_history(line);
	ft_check(line);		
}*/
/*ctrl + tab = switch file on group in vscode*/
