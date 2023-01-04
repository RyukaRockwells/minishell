/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:26:57 by nicole            #+#    #+#             */
/*   Updated: 2023/01/04 18:59:08 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_builtin(char *str, t_data *data)
{
	if (ft_strnstr(str, "echo", ft_strlen(str)))
		return (ft_echo(ft_split_quote(str, ' ')));
	else if (ft_strnstr(str, "cd", ft_strlen(str)))
		return (ft_cd(ft_split_quote(str, ' ')));
	else if (ft_strnstr(str, "pwd", ft_strlen(str)))
		return (ft_pwd());
	else if (ft_strnstr(str, "export", ft_strlen(str)))
		return (1);
	else if (ft_strnstr(str, "unset", ft_strlen(str)))
		return (ft_unset(data, ft_split_quote(str, ' '), 1));
	else if (ft_strnstr(str, "env", ft_strlen(str)))
		return (ft_env(data));
	else if (ft_strnstr(str, "exit", ft_strlen(str)))
		return (ft_builtin_exit(ft_split_quote(str, ' '), data));
	return (0);
}
