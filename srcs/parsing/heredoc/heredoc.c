/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:16:34 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/12 17:18:29 by nchow-yu         ###   ########.fr       */
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
	ft_fdadd_back(&(data->here_fd), new);
	return (new);
}

void	ft_read_here(int fd[2], t_data *data, char *str_here)
{
	int		expand;
	char	*str;

	expand = 0;
	str = str_here;
	if (ft_strchr(str_here, '$') != NULL)
		expand = 1;
	ft_rm_quotes(data, &str_here);
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
	id = fork();
	if (id == -1)
		ft_exit(data);
	if (id == 0)
	{
		signal(SIGINT, SIG_DFL);
		ft_read_here(fd, data, here_tok->value);
	}
	if (close(fd[1]) == -1)
		ft_exit(data);
}
