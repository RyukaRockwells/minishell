/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:44:15 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/22 18:44:36 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
