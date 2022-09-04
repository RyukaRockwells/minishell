/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:28:52 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/04 16:07:35 by sanauth          ###   ########.fr       */
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

void	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	ft_free(data->envp);
	free(data->readline);
	while (i < 1024)/*Pourquoi 1024?*/
	{
		close(i);
		i++;
	}
	exit(0);
}

void	ft_free_lex(t_token *data)
{
	while (data != NULL)
	{
		free(data->value);
		data->next = NULL;
	}
}


/*void	show_token(t_data *data)
{
	t_token	*tmp;
	int		i;

	tmp = data->token;
	i = 0;
	while (tmp != NULL)
	{
		printf("token: %s\n", tmp->value);//a enlever
		printf("type: %d\n", tmp->type);//a enlever
		printf("i = %d\n", i);//a enlever
		printf("len = %ld\n", ft_strlen(tmp->value));//a enlever
		printf("-----------------\n");//a enlever
		tmp = tmp->next;
		i++;
	}
}
*/
