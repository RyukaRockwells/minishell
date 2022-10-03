/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:01:44 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/03 16:10:21 by nchow-yu         ###   ########.fr       */
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

void	ft_expand_token(t_data *data, t_token *token)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tok->value[i] != '\0')
	{
		if (tok->value[i] == '\'')
			j = 1 - j;
		if (tok->value[i] == '$' && j != 0)
		{
			if (tok->value[i + 1] == '?')
				ft_expand_pipe(data, &tok->value, &i);
			else
				ft_expand(data, &tok->value, &i);
		}
		i++;
	}
}

void	ft_expand_pipe(t_data *data, char **str, int *i)
{
	char	*tmp;

	
}
