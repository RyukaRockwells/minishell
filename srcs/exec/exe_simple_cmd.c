/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:16:16 by nicole            #+#    #+#             */
/*   Updated: 2022/12/17 17:13:59 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exe_cmd_simple(t_data *data)
{
	pid_t	p_exe;
	int		status;
	char	*lst_cmd;
	int		is_hd;

	is_hd = ft_is_heredoc(data->readline);
	if (is_hd == 1)
	{
		lst_cmd = ft_rm_heredoc_in_str(data->readline);
	}
	else if (ft_is_rd(data->readline) == 0)
		lst_cmd = ft_is_redirect(data->readline, data);
	else
		lst_cmd = ft_strdup(data->readline);
	if (ft_cmd_is_empty(lst_cmd) == 0)
	{
		//lst_cmd = ft_rm_quotes(lst_cmd);
		p_exe = fork();
		if (p_exe == 0)
		{
			ft_choose_fd(is_hd, data, data->readline);
			execute(lst_cmd, data->envp, data);
		}
		waitpid(p_exe, &status, 0);
	}
	free(lst_cmd);
}
