/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:16:16 by nicole            #+#    #+#             */
/*   Updated: 2023/01/08 22:15:36 by nchow-yu         ###   ########.fr       */
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

	is_hd = ft_is_heredoc(data->readline);
	lst_cmd = ft_rdline_choose(is_hd, data, data->readline);
	if (ft_cmd_is_empty(lst_cmd) == 0)
	{
		if (ft_is_builtin(lst_cmd) == 1)
			ft_builtin_no_fork(data, is_hd, lst_cmd);
		else
		{
			p_exe = fork();
			if (p_exe == 0)
			{
				ft_choose_fd(is_hd, data, data->readline);
				execute(lst_cmd, data->envp, data);
			}
			ft_end_of_ft_simple_cmd(data);
		}
	}
	free(lst_cmd);
}
