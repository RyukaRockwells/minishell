/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:09:10 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/10 17:26:27 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_empty_tok(t_token *tok)
{
	while (tok != NULL)
	{
		if (tok->type != ESPACE)
			return (1);
		tok = tok->next;
	}
	return (0);
}

int	ft_check_redirect(t_token *tmp)
{
	if (tmp->type == REDIRECT_IN || tmp->type == REDIRECT_OUT
		|| tmp->type == D_REDIRECT_OUT)
	{
		if (tmp->next == NULL)
			return (ERROR);
		if (tmp->next->type == ESPACE)
		{
			if (tmp->next->next == NULL)
				return (ERROR);
			if (ft_check_next_tok(tmp->next->next->type) != 0)
				return (ft_check_next_tok(tmp->next->next->type));
		}
		if (tmp->next->type != ESPACE)
			if (ft_check_next_tok(tmp->next->type) != 0)
				return (ft_check_next_tok(tmp->next->type));
	}
	return (0);
}

int	ft_pre_check(t_token *tok)
{
	if (ft_empty_tok(tok) == 0)
		return (EMPTY_TOK);
	if (tok->type == PIPE)
		return (PIPE_ERROR);
	if (tok->type == ESPACE)
		if (tok->next->type == PIPE)
			return (PIPE_ERROR);
	return (0);
}

int	ft_check_next_tok(int type)
{
	if (type == PIPE)
		return (PIPE_ERROR);
	if (type == REDIRECT_IN)
		return (REDIR_IN_ERROR);
	if (type == REDIRECT_OUT)
		return (REDIR_OUT_ERROR);
	if (type == D_REDIRECT_OUT)
		return (D_REDIR_OUT_ERROR);
	return (0);
}
