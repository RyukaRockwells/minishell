/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:16:34 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/06 20:10:34 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_close_here(t_data *data)
{
	int		i;

	i = 0;
	ft_free_tab(data->envp);
	ft_free_all(data);
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(0);
}

void	ft_write_in_fd(int delimiter_found, char *tmp, int fd)
{
	if (delimiter_found == 0)
	{
		write(fd, tmp, ft_strlen(tmp));
		write(fd, "\n", 1);
	}
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
			tmp = ft_expand_h(data, tmp);
		ft_write_in_fd(delimiter_found, tmp, fd);
		free(tmp);
	}
	get_next_line(-1);
	ft_close_here(data);
}

int	ft_check_heredoc(t_data *data, t_token *here_tok)
{
	int		id;
	int		fd[2];

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (pipe(fd) == -1)
		ft_exit(1);
	id = fork();
	if (id == -1)
		ft_exit(1);
	if (id == 0)
	{
		signal(SIGINT, SIG_DFL);
		ft_read_heredoc(fd[1], data, here_tok->value);
	}
	data->last_fd = fd[0];
	if (close(fd[1]) == -1)
		ft_exit_here();
	ft_waitpid_h(data, id);
	if (data->last_pipe == EXIT_HEREDOC)
		return (EXIT_HEREDOC);
	return (0);
}
