/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:12:56 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/14 22:12:21 by nicole           ###   ########.fr       */
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
		printf("\n");
}

void	ft_catch_ctrld_h(t_data *data, char *eof)
{
	int		i;

	i = 0;
	printf("Minichouille: warning: here-document");
	printf("delimited by end_of_file (wanted `%s')\n", eof);
	ft_free(data->envp);
	ft_reinit(data);
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(0);
}
//CRTL-C et D vont agir pareil dans le sujet c'est pas demander de gerer les signaux
//du heredoc
