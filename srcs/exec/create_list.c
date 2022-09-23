/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:49:24 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/23 19:17:30 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//pas besoin de i
t_exe	*ft_create_list(t_data *data, int nb_pipe)
{
	int		i;
	t_exe	*new;
	t_exe	*exe;

	i = 0;
	new = NULL;
	while (i < nb_pipe)
	{
		exe = ft_new_exelst(data);
		exe->i = i;
		ft_addexe(&exe, new);
		i++;
	}
	return (exe);
}

t_exe	*ft_new_exelst(t_data *data)
{
	t_exe	*new;

	new = malloc(sizeof(t_exe));
	if (new == NULL)
		ft_exit(data);
	new->cmd = malloc(sizeof(char *));
	if (new->cmd == NULL)
		ft_exit(data);
	(new->cmd)[0] = NULL;
	new->in = -1;
	new->out = -1;
	new->i = -1;
	new->pb = 0;
	new->pid = -1;
	new->next = NULL;
	return (new);
}

void	show_exe(t_data *data)
{
	t_exe	*tmp;

	tmp = data->exe;
	if (tmp == NULL)
		printf("NULL\n");
	else
		printf("NO NULL\n");
}
/*
	exe_list = malloc(sizeof(t_exe));
	if (exe_list != NULL)
		ft_exit(data);
	exe_list->cmd = malloc(sizeof(char *));
	if (exe_list->cmd != NULL)
		ft_exit(data);
	(exe_list->cmd)[0] = NULL;
	exe_list->in = -1;
	exe_list->out = -1;
	exe_list->i = i;
	exe_list->pid = -1;
	exe_list->next = NULL;
*/
