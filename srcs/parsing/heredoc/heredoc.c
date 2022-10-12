/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:16:34 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/12 15:58:39 by nicole           ###   ########.fr       */
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
	ft_rm_quotes(data, &str_here);
	ft_exe_heredoc(fd, expand, data, str_here);
	ft_free(data->envp);
	ft_reinit(data);
	perror(NULL);
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(0);
}

void	ft_exe_heredoc(int fd[2], int expand, t_data *data, char *str_here)
{
	char	*tmp;
	char	*str;

	str = NULL;
	tmp = ft_strdup("");
	while (1)
	{
		if (signal(SIGINT, &ft_sigint))
		{
			free(tmp);
			ft_reinit(data);
		}
		str = readline("heredoc> ");
		if (str == NULL)
		{
			ft_free(data->envp);
			free(tmp);
			free(data->data);
			ft_catch_ctrld_h(data, str_here);
		}
		fprintf(stderr, "str = %s\n", str);
		fprintf(stderr, "str_here = %s\n", str_here);
		if (ft_strcmp(str, str_here) == 0)
			break ;
		if (expand > 0 && ft_strchr(str, '$') != NULL)
			ft_expand_h(data, &str);
		write(fd[1], str, ft_strlen(str));
		write(fd[1], "\n", 1);
		free(str);
	}
	free(tmp);
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
