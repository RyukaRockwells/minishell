/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:16:16 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 19:18:08 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_end_of_ft_simple_cmd(t_data *data)
{
	int		status;

	ft_signore();
	waitpid(0, &status, 0);
	ft_sigreset();
	ft_set_code_exit(data, status);
}

void	ft_exe_simple_cmd(t_data *data)
{
	pid_t	p_exe;
	char	*lst_cmd;
	int		is_hd;
	char	**split_cmd;

	is_hd = ft_is_heredoc(data->readline);
	lst_cmd = ft_rdline_choose(is_hd, data, data->readline);
	split_cmd = ft_split_quote(lst_cmd, ' ');
	if (ft_cmd_is_empty(lst_cmd) == 0)
	{
		if (ft_is_builtin(split_cmd) == 1)
			ft_builtin_no_fork(split_cmd, data, is_hd, lst_cmd);
		else
		{
			p_exe = fork();
			if (p_exe == 0)
			{
				ft_free_tab(split_cmd);
				ft_choose_fd(is_hd, data, data->readline);
				execute(lst_cmd, data->envp, data);
			}
			ft_end_of_ft_simple_cmd(data);
		}
	}
	ft_free_tab(split_cmd);
	free(lst_cmd);
}
