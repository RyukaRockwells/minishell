/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:12:56 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/12 14:00:08 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_catch_signal(void)
{
	signal(SIGINT, &ft_catch_int);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_catch_d(t_data *data)
{
	write(1, "exit\n", 6);
	free(data->readline);
	ft_free_tab(data->envp);
	ft_exit(1);
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
		printf("\n");
}

void	ft_catch_ctrld_h(t_data *data, char *eof)
{
	int		i;

	i = 0;
	printf("\nMinichouille: warning: here-document");
	printf("delimited by end_of_file (wanted `%s')\n", eof);
	ft_free_tab(data->envp);
	ft_reinit(data);
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(0);
}
