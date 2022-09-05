/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:42:06 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/05 13:33:48 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_tokenadd_back(t_token **tok, t_token *new)
{
	t_token	*last_elmt;

	if (tok != NULL)
	{
		if (*tok == NULL)
			*tok = new;
		else
		{
			last_elmt = ft_tokenlast(*(tok));
			last_elmt->next = new;
		}
	}
}

t_token	*ft_tokenlast(t_token *tok)
{
	if (tok != NULL)
	{
		while (tok->next != NULL)
			tok = tok->next;
	}
	return (tok);
}
