/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:16:34 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/04 16:59:51 by nicole           ###   ########.fr       */
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

	expand = 0;
	str = str_here;
	if (ft_strchr(str_here, '\'') != NULL && ft_strchr(str_here, '\"') != NULL)
		expand = 1;
	ft_rm_quotes(data, &str_here);
	printf("str_here: %s\n", str_here);
}

void	ft_exe_heredoc(int fd[2], int expand, t_data *data, char *str_here)
{
	char	*tmp;
	char	*str;

	str = NULL;
	tmp = ft_strdup("");
	while (1)
	{
		signal(SIGINT, &ft_sigint);
		str = readline("heredoc> ");
		if (str == NULL)
			ft_catch_ctrld_h(data, str_here);
		if (ft_strcmp(str, str_here) == 0)
			break ;
		if (expand > 0 && ft_strchr(str, '$') != NULL)
			//ft_expand_dollar(data, &str);
			printf("Pandawa\n");
	}
}

//SIG_IN ignore les signaux renseigne
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
