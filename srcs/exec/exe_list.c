/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:44:15 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/23 15:14:21 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exe_lst(t_data *data)
{
	while (data->tok_exe != NULL)
	{
		if (data->tok_exe->type == PIPE)
			data->nb_pipe++;
		data->tok_exe = data->tok_exe->next;
	}
	data->tok_exe = ft_create_list(data);
	show_exe(data);
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

/*

int	ft_count_pipe(t_data *data, t_token *token_list)
{
	int	nb_of_pipe;

	(void)data;
	nb_of_pipe = 0;
	while (token_list)
	{
		if (token_list->type == T_PIPE)
			nb_of_pipe += 1;
		token_list = token_list->next;
	}
	return (nb_of_pipe);
}
*/
