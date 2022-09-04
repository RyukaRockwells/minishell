/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:12:56 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/04 15:17:29 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_catch_signal(void)
{
	signal(SIGINT, &ft_catch_int);
	signal(SIGQUIT, &ft_catch_quit);
}

void	ft_catch_d(t_data *data)
{
	write(1, "exit\n", 6);
	ft_free_lex(data->token);
	ft_exit(data);
}

void	ft_catch_quit(int signal)
{
	if (signal == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 1);
}

void	ft_catch_int(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 2);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}
