/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:09:10 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/25 16:24:44 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_empty_tok(t_token *tok)
{
	while (tok != NULL)
	{
		if (tok->type != ESPACE)
			return (1);
		tok = tok->next;
	}
	return (0);
}

/*int	ft_check_pipe(t_token *tok)
{
	t_token	*tok;
	int		state;

	tok = data->token;
	state = 0;
}*/

int	ft_check_redirect(t_token *tmp)
{
	if (tmp->type == REDIRECT_IN || tmp->type == REDIRECT_OUT
		|| tmp->type == D_REDIRECT_OUT)
	{
		if (tmp->next == NULL)
			return (NEWLINE_ERROR);
		if (tmp->next->type == ESPACE)
		{
			if (tmp->next->next == NULL)
				return (NEWLINE_ERROR);
			if (ft_check_next_tok(tmp->next->next->type) != 0)
				return (ft_check_next_tok(tmp->next->next->type));
		}
		if (tmp->next->type != ESPACE)
			if (ft_check_next_tok(tmp->next->type) != 0)
				return (ft_check_next_tok(tmp->next->type));
	}
	return (0);
}

int	ft_pre_check(t_token *tok)
{
	if (ft_empty_tok(tok) == 0)
		return (EMPTY_TOK);
	if (tok->type == PIPE)
		return (PIPE_ERROR);
	if (tok->type == ESPACE)
		if (tok->next->type == PIPE)
			return (PIPE_ERROR);
	return (0);
}

int	ft_check_next_tok(int type)
{
	if (type == PIPE)
		return (PIPE_ERROR);
	if (type == REDIRECT_IN)
		return (REDIR_IN_ERROR);
	if (type == REDIRECT_OUT)
		return (REDIR_OUT_ERROR);
	if (type == D_REDIRECT_OUT)
		return (D_REDIR_OUT_ERROR);
	if (type == HEREDOC)
		return (HEREDOC_ERROR);
	return (0);
}

/*
void	ft_build_exec_list(t_data *data)
{
	ft_create_exec_elm_list(data);
	ft_fill_exec_list_cmd__and_redirect(data);
}

void	ft_create_exec_elm_list(t_data *data)
{
	data->nb_of_process = ft_count_pipe(data, data->gp_tokens_list) + 1;
	data->exec_list = ft_create_empty_exec_elm_list(data, data->nb_of_process);
	ft_create_pipe_between_process(data);
}
l.h"

t_exec_elm	*ft_create_empty_exec_elm_list(t_data *data, int nb_elm)
{
	int			i;
	t_exec_elm	*list;
	t_exec_elm	*new_exec_elm;

	i = 0;
	list = NULL;
	while (i < nb_elm)
	{
		new_exec_elm = ft_create_new_exec_elm(data);
		new_exec_elm->index = i;
		ft_add_exec_elm(&list, new_exec_elm);
		i++;
	}
	return (list);
}

t_exec_elm	*ft_create_new_exec_elm(t_data *data)
{
	t_exec_elm	*new_elm;

	new_elm = ft_malloc(data, sizeof(t_exec_elm));
	if (!new_elm)
		ft_exit(data);
	new_elm->cmd = ft_malloc(data, sizeof(char *) * 1);
	if (!new_elm->cmd)
		ft_exit(data);
	(new_elm->cmd)[0] = NULL;
	new_elm->fd_in = -1;
	new_elm->fd_out = -1;
	new_elm->index = -1;
	new_elm->has_redirect_pb = 0;
	new_elm->pid = -1;
	new_elm->next = NULL;
	return (new_elm);
}

void	ft_add_exec_elm(t_exec_elm **elm_list, t_exec_elm *new_elm)
{
	t_exec_elm	*last;

	if (*elm_list == NULL)
	{
		*elm_list = new_elm;
		return ;
	}
	if (new_elm != 0)
	{
		last = ft_get_last_exec_elm(*elm_list);
		last->next = new_elm;
	}
}

static void	ft_create_pipe_between_process(t_data *data)
{
	int	i;
	int	*fd_pipe;

	i = 0;
	ft_get_exec_elm(data->exec_list, 0)->fd_in = 0;
	ft_get_exec_elm(data->exec_list, data->nb_of_process - 1)->fd_out = 1;
	while (i < data->nb_of_process - 1)
	{
		fd_pipe = ft_create_pipe(data);
		ft_get_exec_elm(data->exec_list, i)->fd_out = fd_pipe[1];
		ft_get_exec_elm(data->exec_list, i + 1)->fd_in = fd_pipe[0];
		i++;
	}
}

t_exec_elm	*ft_get_exec_elm(t_exec_elm *lst, int index)
{
	int	i;

	if (!lst)
		return (NULL);
	i = 0;
	while (lst)
	{
		if (i == index)
			return (lst);
		i++;
		lst = lst->next;
	}
	return (NULL);
}

static int	*ft_create_pipe(t_data *data)
{
	int	*fd_pipe;

	fd_pipe = ft_malloc(data, sizeof(int) * 2);
	if (!fd_pipe)
		ft_exit(data);
	if (pipe(fd_pipe) == -1)
		ft_exit_pipe_error(data);
	return (fd_pipe);
}

*/
