/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:26:57 by nicole            #+#    #+#             */
/*   Updated: 2023/01/03 23:50:17 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_builtin(char *str, t_data *data)
{
	/*if (ft_strnstr(str, "echo", ft_strlen(str)))
		return (1);
	else*/if (ft_strnstr(str, "cd", ft_strlen(str)))
		return (ft_cd(ft_split_quote(data->readline, ' ')));
	else if (ft_strnstr(str, "pwd", ft_strlen(str)))
		return (ft_pwd());
	else if (ft_strnstr(str, "export", ft_strlen(str)))
		return (1);
	else if (ft_strnstr(str, "unset", ft_strlen(str)))
		return (1);
	else if (ft_strnstr(str, "env", ft_strlen(str)))
		return (ft_benv(data));
	else if (ft_strnstr(str, "exit", ft_strlen(str)))
		return (ft_builtin_exit(data->readline, data));
	return (0);
}

int ft_benv(t_data *data)
{
	ft_print_env(data);
	return (1);
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
	return (1);
}

void	ft_builtin(char *str)
{
	ft_putstr_fd("This is a builtin\n", 1);
	fprintf(stderr, "builtin str == %s\n", str);
	if (ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
		ft_pwd();
	else
		printf("pas pwd\n");
}

int	ft_builtin_exit(char *str, t_data *data)
{
	int	i;
	int	exit_code;

	i = 0;
	exit_code = ft_atoi(str);
	if (ft_strncmp(str, "exit", ft_strlen(str)) == 0)
	{
		ft_free_all(data);
		ft_free(data->envp);
		exit(0);
	}
	else if (str != NULL)
	{
		if (str[0] == '-' || str[0] == '+')
			i++;
		while (str[i] != '\0')
		{
			if (ft_isdigit(str[i]) == 0)
			{
				ft_putstr_fd("exit\n", 2);
				ft_putstr_fd("minishell: exit: ", 2);
				ft_putstr_fd(str, 2);
				ft_putstr_fd(": numeric argument required\n", 2);
				ft_free_all(data);
				ft_free(data->envp);
				exit(2);
			}
			i++;
		}
	}
	else
	{
		ft_free_all(data);
		ft_free(data->envp);
	}
	exit(exit_code);
	return (1);
}

int	ft_cd(char **path_tab)
{
	int	i;

	i = 1;
	printf("JESUISCDCDCDCD\n");
	while (path_tab[i] != NULL)
	{
		printf("HELLOO path_tab[i] = %s\n", path_tab[i]); //printf de controle de pathtab
		i++;
	}
	if (!path_tab)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd("Missing path", 2);
		return (1);
	}
	if (i > 1)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd("Too many arguments", 2);
		return (1);
	}
	printf("path_tab[i] = %s\n", path_tab[i]);
	if (chdir(path_tab[i]) == -1)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(path_tab[i], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	return (0);
}
