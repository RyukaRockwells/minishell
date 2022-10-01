/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:28:52 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/01 19:47:03 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

/*
enlever le while et le close pour le remplacer dans
ft_free_token_list par close(tmp->fd);
ps: rajouter dans la structure token un :
int fd;
*/
void	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		close(i);
		i++;
	}
	exit(0);
}

void	ft_exit_here(t_data *data)
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
