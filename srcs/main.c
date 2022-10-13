/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:19:26 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/12 19:06:19 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int nb, char **arg, char **envp)
{
	t_data	data;

	(void)arg;
	if (nb != 1)
		ft_error();
	ft_init(envp, &data);
	ft_loop(&data);
	return (0);
}
