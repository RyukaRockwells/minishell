/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:21:49 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/27 22:55:15 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_check_cmd_redirect(t_data *data)
{
	int		i;
	t_token	*tok;
	t_exe	*exe;

	i = 0;
	tok = data->tok_exe;
	while (tok != NULL)
	{
		if (tok->type == PIPE)
			i++;
		exe = ft_get_idexe(data->exe, i);
		if (tok->type == HEREDOC)
			ft_check_heredoc(data, i);
		tok = tok->next;
	}
}

void	ft_check_heredoc(t_data *data, int i)
{
	t_fd	*fd;

	fd = ft_fd_heredoc(data);
	if (ft_get_idexe(data->exe, i)->fd_in != 0)
		close(ft_get_idexe(data->exe, i)->fd_in);
	ft_get_idexe(data->exe, i)->fd_in = fd->fd_in;
	//free(data, fd_heredoc);
}

// free un element du garbage collector
// void	ft_free(t_data *data, void *address)
// {
// 	t_list	*previous;
// 	t_list	*next;
// 	t_list	*elm;

// 	if (!address)
// 		return ;
// 	elm = data->garbage_collector;
// 	previous = NULL;
// 	while (elm)
// 	{
// 		next = elm->next;
// 		if (elm->content == address)
// 		{
// 			free(elm->content);
// 			elm->content = NULL;
// 			if (previous == NULL)
// 				data->garbage_collector = next;
// 			else
// 				previous->next = elm->next;
// 			free(elm);
// 		}
// 		previous = elm;
// 		elm = next;
// 	}
// }
