/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 01:51:10 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 16:57:23 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_no_argument(char **path_tab)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd("Missing path\n", 2);
	ft_free_tab(path_tab);
	return (1);
}

int	ft_too_many_argument(char **path_tab)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd("Too many arguments\n", 2);
	ft_free_tab(path_tab);
	return (1);
}

int	ft_cd(char **path_tab)
{
	int	i;

	i = 1;
	while (path_tab[i] != NULL)
		i++;
	if (!path_tab[1])
		return (ft_no_argument(path_tab));
	if (i != 2)
		return (ft_too_many_argument(path_tab));
	if (chdir(path_tab[1]) == -1)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(path_tab[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		ft_free_tab(path_tab);
		return (1);
	}
	return (0);
}
