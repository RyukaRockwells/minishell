/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:01:44 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/04 16:28:49 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_add_exe_h(t_data *data, int i)
{
	t_fd	*fd;

	fd = ft_fd_heredoc(data, i);
	if (ft_get_idexe(data->exe, i)->in != 0)
		close(ft_get_idexe(data->exe, i)->in);
	ft_get_idexe(data->exe, i)->in = fd->fd;
	ft_free_fd_heredoc(data);
}

void	ft_add_exe_cmd(t_data *data, t_token *tok_exe, int i)
{
	char	**str_cmd;
	char	**new_cmd;
	int		j;

	ft_expand_token(data, tok_exe);
}