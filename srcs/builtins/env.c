/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 01:52:46 by nicole            #+#    #+#             */
/*   Updated: 2023/01/04 02:01:52 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i] != NULL)
	{
		ft_putstr_fd(data->envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return (1);
}
