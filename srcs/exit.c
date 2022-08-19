/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:28:52 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/19 19:00:40 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	free(data->envp);
	free(data->readline);
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(0);
}
