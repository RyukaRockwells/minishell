/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:49:24 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/25 18:29:00 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		ft_addexe(&new, exe);
		i++;
	}
	return (new);
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
	printf("show_exe\n");
	if (tmp == NULL)
		printf("\nNULL\n\n");
	else
		printf("exe->in = %d\nexe->out = %d\n\n", tmp->in, tmp->out);
}

int	*ft_create_pipe(t_data *data)
{
	int	*fd;
	int	i;

	fd = malloc(sizeof(int) * 2);
	i = 0;
	if (fd == NULL)
		ft_exit(data);
	if (pipe(fd) == -1)
	{
		ft_free(data->envp);
		free(data->readline);
		while (i < 1024)
		{
			close(i);
			i++;
		}
		exit(1);
	}
	return (fd);
}

void	ft_fd_exec(t_data *data)
{
	int	i;
	int	*fd;

	i = 0;
	ft_get_idexe(data->exe, 0)->in = 0;
	ft_get_idexe(data->exe, data->nb_pipe - 1)->out = 1;
	while (i < data->nb_pipe - 1)
	{
		fd = ft_create_pipe(data);
		ft_get_idexe(data->exe, i)->out = fd[1];
		ft_get_idexe(data->exe, i + 1)->in = fd[0];
		i++;
	}
}

// void	ft_free_exe(t_exe *exe)
// {
// 	int	i;

// 	i = 0;
// 	if (exe != NULL)
// 	{
// 		while (exe->cmd[i] != NULL)
// 		{
// 			free(exe->cmd[i]);
// 			i++;
// 		}
// 		free(exe->cmd);
// 		free(exe);
// 	}
// }
