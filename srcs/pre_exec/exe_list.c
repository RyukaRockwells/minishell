/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:44:15 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/11/27 14:57:16 by nicole           ###   ########.fr       */
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
}
