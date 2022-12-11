/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:26:57 by nicole            #+#    #+#             */
/*   Updated: 2022/12/11 17:52:35 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_builtin(char *str)
{
	/*if (ft_strnstr(str, "echo", ft_strlen(str)))
		return (1);
	else */if (ft_strnstr(str, "cd", ft_strlen(str)))
		return (1);
	else if (ft_strnstr(str, "pwd", ft_strlen(str)))
		return (1);
	else if (ft_strnstr(str, "export", ft_strlen(str)))
		return (1);
	else if (ft_strnstr(str, "unset", ft_strlen(str)))
		return (1);
	else if (ft_strnstr(str, "env", ft_strlen(str)))
		return (1);
	else if (ft_strnstr(str, "exit", ft_strlen(str)))
		return (1);
	return (0);
}

int	ft_pwd(void)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, 0);
	if (pwd == NULL)
		return (1);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}

void	ft_builtin(char *str)
{
	ft_putstr_fd("This is a builtin\n", 1);
	fprintf(stderr, "builtin str == %s\n", str);
	if (ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
		ft_pwd();
	else
		printf("pas pwd");
}
