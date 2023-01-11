/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:26:57 by nicole            #+#    #+#             */
/*   Updated: 2023/01/11 16:50:06 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_builtin_no_fork(t_data *data, int is_hd, char *lst_cmd)
{
	int	old_in;
	int	old_out;

	old_in = dup(0);
	old_out = dup(1);
	ft_choose_fd(is_hd, data);
	if (data->file_exit == 0)
		ft_builtin(data, lst_cmd);
	dup2(old_in, 0);
	dup2(old_out, 1);
	close(old_in);
	close(old_out);
}

int	ft_is_builtin(char *lst_cmd)
{
	int		is_builtin;
	char	**split_cmd;

	is_builtin = 0;
	split_cmd = ft_split_quote(lst_cmd, ' ');
	if (ft_strcmp(split_cmd[0], "echo") == 0)
		is_builtin = 1;
	else if (ft_strcmp(split_cmd[0], "cd") == 0)
		is_builtin = 1;
	else if (ft_strcmp(split_cmd[0], "pwd") == 0)
		is_builtin = 1;
	else if (ft_strcmp(split_cmd[0], "exit") == 0)
		is_builtin = 1;
	else if (ft_strcmp(split_cmd[0], "export") == 0)
		is_builtin = 1;
	else if (ft_strcmp(split_cmd[0], "unset") == 0)
		is_builtin = 1;
	else if (ft_strcmp(split_cmd[0], "env") == 0)
		is_builtin = 1;
	ft_free_tab(split_cmd);
	return (is_builtin);
}

int	ft_builtin(t_data *data, char *lst_cmd)
{
	int		return_ft;
	char	**split_cmd;

	return_ft = 2;
	split_cmd = ft_split_quote(lst_cmd, ' ');
	if (ft_strcmp(split_cmd[0], "echo") == 0)
		return_ft = ft_echo(split_cmd);
	else if (ft_strcmp(split_cmd[0], "cd") == 0)
		return_ft = ft_cd(split_cmd);
	else if (ft_strcmp(split_cmd[0], "pwd") == 0)
		return_ft = ft_pwd();
	else if (ft_strcmp(split_cmd[0], "export") == 0)
		return_ft = ft_export(split_cmd, data->envp, data);
	else if (ft_strcmp(split_cmd[0], "unset") == 0)
		return_ft = ft_unset(data, split_cmd);
	else if (ft_strcmp(split_cmd[0], "env") == 0)
		return_ft = ft_env(data);
	else if (ft_strcmp(split_cmd[0], "exit") == 0)
		return_ft = ft_builtin_exit(split_cmd, data, lst_cmd);
	ft_free_tab(split_cmd);
	return (return_ft);
}
