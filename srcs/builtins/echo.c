/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:25:51 by sanauth           #+#    #+#             */
/*   Updated: 2022/10/24 15:33:59 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//void	ft_echo(t_data *data, char **args)
// modifier main mais renommer
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

int	ft_print(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

int	ft_echo(int ac, char **args)
{
	int	i;

	if (ac >= 0)
	{
		i = 1;
		if (args[1] == NULL)
		{
			ft_putchar_fd('\n', 1);
			return (0);
		}
		while (args[i] != NULL)
		{
			if (ft_option(args[i]) == 1)
				i++;
			else
				break ;
		}
		while (args[i] != NULL)
		{
			ft_print(args[i]);
			if (args[i + 1] != NULL)
			{
				ft_putchar_fd(' ', 1);
			}
			i++;
		}
	}
	if (ft_option(args[1]) == 0)
		ft_putchar_fd('\n', 1);
	return (0);
}
