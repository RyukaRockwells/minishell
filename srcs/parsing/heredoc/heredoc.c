/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:16:34 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/13 20:39:54 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_fd	*ft_start_fd(t_data *data, int fd)
{
	t_fd	*new;

	new = malloc(sizeof(t_fd));
	if (new == NULL)
		ft_exit(data);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

void	ft_read_here(int fd[2], t_data *data, char *str_here)
{
	int		expand;
	char	*str;
	int		i;

	i = 0;
	expand = 0;
	str = str_here;
	if (ft_strchr(str_here, '\'') != NULL && ft_strchr(str_here, '\"') != NULL)
		expand = 1;
	ft_rm_quotes(data, &str);
	ft_exe_heredoc(fd[1], expand, data, str);
	ft_free(data->envp);
	ft_reinit(data);
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(0);
}

void	ft_exe_heredoc(int fd, int expand, t_data *data, char *str_here)
{
	char	*tmp;
	int		delimiter_found;

	tmp = "";
	delimiter_found = 0;
	signal(SIGINT, &ft_sigint);
	while (delimiter_found == 0)
	{
		write(1, "heredoc> ", 9);
		tmp = get_next_line(0);
		if (ft_strcmp(tmp, str_here) == 0)
			delimiter_found = 1;
		if (expand > 0 && ft_strchr(tmp, '$') != NULL)
			ft_expand_h(data, &tmp);
		write(fd, tmp, ft_strlen(tmp));
		free(tmp);
	}
	get_next_line(-1);
}

//SIG_IN ignore les signaux renseigné
int	ft_check_heredoc(t_data *data, t_token *here_tok)
{
	int		id;
	int		fd[2];
	t_fd	*here_fd;

	here_fd = NULL;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (pipe(fd) == -1)
		ft_exit(data);
	here_fd = ft_start_fd(data, fd[0]);
	ft_fdadd_back(&data->last_fd, here_fd);
	id = fork();
	if (id == -1)
		ft_exit(data);
	if (id == 0)
	{
		signal(SIGINT, SIG_DFL);
		ft_read_here(fd, data, here_tok->value);
	}
	if (close(fd[1]) == -1)
		ft_exit_here(data);
	ft_waitpid_h(data, id);
	if (data->last_pipe == EXIT_HEREDOC)
		return (EXIT_HEREDOC);
	return (0);
}
