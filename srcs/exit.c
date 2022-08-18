/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:28:52 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/18 11:30:37 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_exit(t_list *list)
{
	int	i;

	i = 0;
	free(list->envp);
	free(list->readline);
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(0);
}
