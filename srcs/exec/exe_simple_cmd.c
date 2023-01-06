/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:16:16 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 17:39:06 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exe_simple_cmd(t_data *data)
{
	pid_t	p_exe;
	int		status;
	char	*lst_cmd;
	int		is_hd;
	char	**split_cmd;

	is_hd = ft_is_heredoc(data->readline);
	lst_cmd = ft_rdline_choose(is_hd, data, data->readline);
	split_cmd = ft_split_quote(lst_cmd, ' ');
	if (ft_cmd_is_empty(lst_cmd) == 0)
	{
		if (ft_is_builtin(split_cmd) == 1)
		{
			ft_builtin_no_fork(split_cmd, data, is_hd);
			free(lst_cmd);
			ft_free_tab(split_cmd);
			return ;
		}
		ft_free_tab(split_cmd);
		p_exe = fork();
		if (p_exe == 0)
		{
			ft_choose_fd(is_hd, data, data->readline);
			execute(lst_cmd, data->envp, data);
		}
		ft_signore();
		waitpid(0, &status, 0);
		ft_sigreset();
		ft_set_code_exit(data, status);
	}
	free(lst_cmd);
}
