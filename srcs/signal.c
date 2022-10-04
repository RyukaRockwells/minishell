/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:12:56 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/04 19:21:17 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_catch_signal(void)
{
	signal(SIGINT, &ft_catch_int);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_catch_d(t_data *data)
{
	write(1, "exit\n", 6);
	ft_free(data->envp);
	ft_exit(data);
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

void	ft_sigint(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		exit(130);
	}
}

void	ft_catch_ctrld_h(t_data *data, char *eof)
{
	printf("Minichouille: warning: here-document");
	printf("delimited by end_of_file (wanted `%s')\n", eof);
	ft_reinit(data);
	ft_exit(data);
}
