/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:25:25 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/08 13:35:06 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pre_parser(t_token *list)
{
	if (ft_is_empty_list(list) == 0)
		return (EMPTY_TOK);
	if (list->type == PIPE)
		return (PIPE_ERROR);
	if (list->type == ESPACE)
	{
		if (list->next->type == PIPE)
			return (PIPE_ERROR);
	}
	return (0);
}

int	ft_is_empty_list(t_token *list)
{
	while (list != NULL)
	{
		if (list->type != ESPACE)
			return (1);
		list = list->next;
	}
	return (0);
}
