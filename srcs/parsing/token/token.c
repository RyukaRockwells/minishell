/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:20:13 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/12/01 07:53:40 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_get_token(t_data *data, char *rdline, int i, int strlen)
{
	char	*wd;

	wd = ft_substr(rdline, i, strlen);
	if (wd == NULL)
		ft_exit();
	ft_add_token(wd, data, LITERAL);
	return (0);
}

void	ft_add_token(char *word, t_data *data, int type)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		ft_exit();
	new->value = word;
	new->type = type;
	new->next = NULL;
	ft_tokenadd_back(&data->token, new);
}

void	ft_addtok(char *word, t_data *data, int type)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		ft_exit();
	new->value = word;
	new->type = type;
	new->next = NULL;
	ft_tokenadd_back(&data->tok_exe, new);
}
