/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:28:52 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/10 20:43:30 by nchow-yu         ###   ########.fr       */
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
	ft_free(data->envp);//a bouger dans token_list
	free(data->readline);//idem
	while (i < 1024)/*Pourquoi 1024?*/
	{
		close(i);
		i++;
	}
	exit(0);
}

void	ft_free_token_list(t_data *data)
{
	t_token	*tmp;

	//dprintf(2,"free token list\n");
	printf("%p\n", data->token);
	while (data->token != NULL)
	{
		//dprintf(2,"TOKEN\n");
		tmp = data->token;
		data->token = data->token->next;
		free(tmp->value);
		tmp->value = NULL;
		free(tmp);
	}
}
