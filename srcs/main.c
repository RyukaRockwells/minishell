/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:19:26 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/08 21:41:50 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int nb, char **arg, char **envp)
{
	t_data	data;

	(void)arg;
	if (nb != 1)
	{
		ft_putstr_fd("Launch minishell with \n./minishell\n", 2);
	}
	ft_init(envp, &data);
	ft_loop(&data);
	return (0);
}
