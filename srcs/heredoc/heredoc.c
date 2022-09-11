/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:16:34 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/11 19:48:11 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_here_fd	*ft_start_fd(t_data *data, int fd)
{
	t_here_fd	*new;

	new = malloc(sizeof(t_here_fd));
	if (new == NULL)
		ft_exit(data);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

//SIG_IN ignore les signaux renseigne
int	ft_check_heredoc(t_data *data, t_token *here_tok)
{
	int			id;
	int			fd[2];
	t_here_fd	*here_fd;

	here_fd = NULL;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (pipe(fd) == -1)
		ft_exit(data);
	here_fd = ft_start_fd(data, fd[0]);
}
