/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:12:56 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/18 11:27:24 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_catch_signal(void)
{
	signal(SIGINT, &ft_signal);
	signal(SIGQUIT, &ft_signal);
}

void	ft_catch_d(t_list *list)
{
	write(1, "exit\n", 6);
	ft_exit(list);
}
