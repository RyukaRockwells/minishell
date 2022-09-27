/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:21:49 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/27 19:42:47 by nchow-yu         ###   ########.fr       */
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
			ft_check_heredoc(data, tok, i);
		tok = tok->next;
	}
}

void	ft_check_heredoc(t_data *data, t_token *tok, int i)
{
	t_
}
