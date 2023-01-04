/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:06:44 by nicole            #+#    #+#             */
/*   Updated: 2023/01/04 20:45:31 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_option(char *str)
{
	int	i;

	i = 1;
	if (str[0] == '-' && str[1] == 'n')
	{
		while (str[i] != '\0')
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_skip_option(char **tab_arg, int *i)
{
	while (tab_arg[(*i)] != NULL)
	{
		if (ft_option(tab_arg[(*i)]) == 1)
			(*i)++;
		else
			break ;
	}
}

int	ft_print(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

int	ft_echo(char **tab_arg)
{
	int	i;

	i = 1;
	if (tab_arg[1] == NULL)
	{
		ft_putchar_fd('\n', 1);
		ft_free(tab_arg);
		return (1);
	}
	ft_skip_option(tab_arg, &i);
	while (tab_arg[i] != NULL)
	{
		ft_putstr_fd(tab_arg[i], 1);
		if (tab_arg[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (ft_option(tab_arg[1]) == 0)
		ft_putchar_fd('\n', 1);
	ft_free(tab_arg);
	return (1);
}
