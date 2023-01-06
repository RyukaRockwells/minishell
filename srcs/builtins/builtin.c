/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:26:57 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 19:07:49 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_builtin_no_fork(char **str, t_data *data, int is_hd, char *lst_cmd)
{
	int	old_in;
	int	old_out;

	old_in = dup(0);
	old_out = dup(1);
	ft_choose_fd(is_hd, data, data->readline);
	if (data->file_exit == 0)
		ft_builtin(str, data, lst_cmd);
	dup2(old_in, 0);
	dup2(old_out, 1);
	close(old_in);
	close(old_out);
}

int	ft_is_builtin(char **str)
{
	if (ft_strcmp(str[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(str[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(str[0], "pwd") == 0)
		return (1);
	else if (ft_strcmp(str[0], "exit") == 0)
		return (1);
	else if (ft_strcmp(str[0], "export") == 0)
		return (1);
	else if (ft_strcmp(str[0], "unset") == 0)
		return (1);
	else if (ft_strcmp(str[0], "env") == 0)
		return (1);
	return (0);
}

int	ft_builtin(char **str, t_data *data, char *lst_cmd)
{
	if (ft_strcmp(str[0], "echo") == 0)
		return (ft_echo(str));
	else if (ft_strcmp(str[0], "cd") == 0)
		return (ft_cd(str));
	else if (ft_strcmp(str[0], "pwd") == 0)
		return (ft_pwd());
	else if (ft_strcmp(str[0], "export") == 0)
		return (ft_export(str, data->envp));
	else if (ft_strcmp(str[0], "unset") == 0)
		return (ft_unset(data, str, 1));
	else if (ft_strcmp(str[0], "env") == 0)
		return (ft_env(data));
	else if (ft_strcmp(str[0], "exit") == 0)
		return (ft_builtin_exit(str, data, lst_cmd));
	return (2);
}
