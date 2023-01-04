/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:26:57 by nicole            #+#    #+#             */
/*   Updated: 2023/01/04 23:53:03 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_builtin(char **str, t_data *data)
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
		return (ft_builtin_exit(str, data));
	return (0);
}
