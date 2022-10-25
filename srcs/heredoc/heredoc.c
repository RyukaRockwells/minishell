/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:16:34 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/25 18:50:25 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_fd	*ft_start_fd(int fd)
{
	t_fd	*new;

	new = malloc(sizeof(t_fd));
	if (new == NULL)
		ft_exit();
	new->fd = fd;
	new->next = NULL;
	return (new);
}

void	ft_close_here(t_data *data)
{
	int		i;

	i = 0;
	ft_free(data->envp);
	ft_free_all(data);
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(0);
}

void	ft_read_heredoc(int fd, t_data *data, char *str_here)
{
	char	*tmp;
	int		delimiter_found;

	tmp = "";
	delimiter_found = 0;
	ft_catch_c_heredoc();
	while (delimiter_found == 0)
	{
		write(1, "heredoc> ", 9);
		tmp = get_next_line(0);
		if (tmp == (char *)-1)
			ft_close_here(data);
		if (tmp == NULL)
			ft_catch_ctrld_h(data, str_here);
		if (ft_strcmp(tmp, str_here) == 0)
			delimiter_found = 1;
		if (ft_strchr(tmp, '$') != NULL)
			ft_expand_h(fd, &tmp);
		write(fd, tmp, ft_strlen(tmp));
		write(fd, "\n", 1);
		free(tmp);
	}
	get_next_line(-1);
	ft_close_here(data);
}

int	ft_check_heredoc(t_data *data, t_token *here_tok)
{
	int		id;
	int		fd[2];
	t_fd	*here_fd;

	here_fd = NULL;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (pipe(fd) == -1)
		ft_exit();
	here_fd = ft_start_fd(fd[0]);
	ft_fdadd_back(&data->last_fd, here_fd);
	id = fork();
	if (id == -1)
		ft_exit();
	if (id == 0)
	{
		signal(SIGINT, SIG_DFL);
		ft_read_heredoc(fd[1], data, here_tok->value);
	}
	if (close(fd[1]) == -1)
		ft_exit_here();
	ft_waitpid_h(data, id);
	if (data->last_pipe == EXIT_HEREDOC)
		return (EXIT_HEREDOC);
	return (0);
}
