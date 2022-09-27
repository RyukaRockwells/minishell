/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:20:13 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/27 19:01:44 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_get_token(t_data *data, char *rdline, int i, int strlen)
{
	char	*wd;

	wd = ft_substr(rdline, i, strlen);
	if (wd == NULL)
		ft_exit(data);
	//free(wd);
	//printf("word dans get_token: %s\n", wd);//a enlever
	ft_add_token(wd, data, LITERAL);
	//free(wd);
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

void	ft_addtok(char *word, t_data *data, int type)
{
	t_token	*new;

	//printf("word: %s\n", word);//a enlever
	new = malloc(sizeof(t_token));
	if (new == NULL)
		ft_exit(data);
	new->value = word;
	new->type = type;
	new->next = NULL;
	ft_tokenadd_back(&data->tok_exe, new);
	//free(new);
}

void	show_token2(t_data *data)
{
	t_token	*tmp;
	int		i;

	tmp = data->tok_exe;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->value)
			printf("tok_exe: %s\n", tmp->value);//a enlever
		else
			printf("no tok_exe\n");
		printf("type 2 : %d\n", tmp->type);//a enlever
		printf("i 2 = %d\n", i);//a enlever
		printf("len 2 = %ld\n", ft_strlen(tmp->value));//a enlever
		if (tmp->next == NULL)
			printf("next = NULL\n");//a enlever
		else if (tmp->next != NULL)
			printf("next 2 = %s\n", tmp->next->value);//a enlever
		printf("-----------------\n");//a enlever
		tmp = tmp->next;
		i++;
	}
}

void	show_token(t_data *data)
{
	t_token	*tmp;
	int		i;

	tmp = data->token;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->value)
			printf("token: %s\n", tmp->value);//a enlever
		else
			printf("no token\n");
		printf("type: %d\n", tmp->type);//a enlever
		printf("i = %d\n", i);//a enlever
		printf("len = %ld\n", ft_strlen(tmp->value));//a enlever
		if (tmp->next == NULL)
			printf("next = NULL\n");//a enlever
		else if (tmp->next != NULL)
			printf("next = %s\n", tmp->next->value);//a enlever
		printf("-----------------\n");//a enlever
		tmp = tmp->next;
		i++;
	}
}
