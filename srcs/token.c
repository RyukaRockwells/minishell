/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:20:13 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/02 16:14:01 by nchow-yu         ###   ########.fr       */
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
	ft_add_token(wd, data, LITERAL);
	return (0);
}

void	ft_add_token(char *word, t_data *data, int type)
{
	t_token	*new;
	t_token	*tmp;

	printf("word: %s\n", word);
	new = malloc(sizeof(t_token));
	if (new == NULL)
		ft_exit(data);
	new->value = word;
	new->type = type;
	new->next = NULL;
	if (data->token == 0)
	{
		data->token = new;
		return ;
	}
	if (new != 0)
	{
		if (new == NULL)
			return ;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	show_token(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp != NULL)
	{
		printf("token: %s\n", tmp->value);
		printf("type: %d\n", tmp->type);
		tmp = tmp->next;
	}
}
