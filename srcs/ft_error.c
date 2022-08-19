/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:26:20 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/19 17:14:45 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_error(void)
{
	ft_putendl_fd("minishell: command not found", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_env(void)
{
	ft_putendl_fd("minishell: env: no such file or directory", 2);
	exit(EXIT_FAILURE);
}

void	show_error(int code_error)
{
	if (code_error == QUOTES_NO_CLOSE)
		ft_putstr_fd("minishell: quotes no close\n", 2);
}
