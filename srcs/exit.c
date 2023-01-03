/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:28:52 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/03 17:16:08 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void	ft_exit(int code_exit)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(code_exit);
}

void	ft_exit_here(void)
{
	int	i;

	i = 0;
	perror(NULL);
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(1);
}
