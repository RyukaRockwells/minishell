/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:20:13 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/04 12:30:23 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//get_quotes sunny
int	ft_get_token(t_data *data, char *rdline, int i, int strlen)
{
	char	*wd;

	wd = ft_substr(rdline, i, strlen);
	if (wd == NULL)
		ft_exit(data);
	//free(wd);
	//printf("word dans get_token: %s\n", wd);//a enlever
	ft_add_token(wd, data, LITERAL);
	return (0);
}

void	ft_add_token(char *word, t_data *data, int type)
{
	t_token	*new;

	//printf("word: %s\n", word);//a enlever
	new = malloc(sizeof(t_token));
	if (new == NULL)
		ft_exit(data);
	new->value = word;
	new->type = type;
	new->next = NULL;
	ft_tokenadd_back(&data->token, new);
	//free(new);
}

void	show_token(t_data *data)
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
