/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:44:15 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/13 19:10:15 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_nb_pipe(t_token *lst)
{
	int	nb;

	nb = 0;
	while (lst != NULL)
	{
		if (lst->type == PIPE)
			nb += 1;
		lst = lst->next;
	}
	return (nb);
}

void	ft_exe_lst(t_data *data)
{
	data->nb_pipe = ft_nb_pipe(data->token);
	data->exe = ft_create_list(data, data->nb_pipe);
	ft_fd_exec(data);
}

t_exe	ft_addexe(t_exe **exe, t_exe *new)
{
	t_exe	*last_elmt;

	if (exe != NULL)
	{
		if (*exe == NULL)
			*exe = new;
		else
		{
			last_elmt = ft_exelast(*(exe));
			last_elmt->next = new;
		}
	}
}

t_exe	*ft_exelast(t_exe *exe)
{
	if (exe != NULL)
	{
		while (exe->next != NULL)
			exe = exe->next;
	}
	return (exe);
}

t_exe	*ft_get_idexe(t_exe *exe, int i)
{
	int	j;

	j = 0;
	if (exe == NULL)
		return (NULL);
	while (exe != NULL)
	{
		if (i == j)
			return (exe);
		j++;
		exe = exe->next;
	}
	return (NULL);
}
