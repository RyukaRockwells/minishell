/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:09:10 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/05 17:15:50 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_check_redirect(t_token *tmp)
{
	if (tmp->type == REDIRECT_IN || tmp->type == REDIRECT_OUT
		|| tmp->type == D_REDIRECT_OUT)
	{
		if (tmp->next == NULL)
			return (NEWLINE_ERROR);
		if (tmp->next->type == ESPACE)
		{
			if (tmp->next->next == NULL)
				return (NEWLINE_ERROR);
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
	if (type == HEREDOC)
		return (HEREDOC_ERROR);
	return (0);
}
