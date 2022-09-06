/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:09:10 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/06 16:32:28 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_empty_tok(t_token *tmp)
{
	if (tmp != NULL)
	{
		if (tmp->type != ESPACE)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

//check s'il y a une redirect
//s'il y a vide apres = error
//s'il y a un espace :
//s'il y a un espace et rien = error
int	ft_check_redirect(t_token *tmp)
{
	if (tmp->type == REDIR_IN || tmp->type == REDIR_OUT
		|| tmp->type == D_REDIRECT_OUT)
	{
		if (tmp->next == NULL)
			return (ERROR);
		if (tmp->next->type == ESPACE)
		{
			if (tmp->next->next == NULL)
				return (ERROR);
			return (ft_check_next_tok(tmp->next->next->type));
		}
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

/*
if (token->next->type == T_SPACE)
{
	if (!token->next->next)
		return (SYNTAX_ERR_NEWLINE);
	if (ft_is_next_tkn_ok(token->next->next->type) != 0)
		return (ft_is_next_tkn_ok(token->next->next->type));
}
if (token->next->type != T_SPACE)
{
	if (ft_is_next_tkn_ok(token->next->type) != 0)
		return (ft_is_next_tkn_ok(token->next->type));
}

int	ft_is_next_tkn_ok(int type)
{
	if (type == T_PIPE)
		return (SYNTAX_ERR_PIPE);
	if (type == T_REDIRECT_IN)
		return (SYNTAX_ERR_REDIRECT_IN);
	if (type == T_REDIRECT_OUT)
		return (SYNTAX_ERR_REDIRECT_OUT);
	if (type == D_REDIRECT_OUT)
		return (SYNTAX_ERR_D_REDIRECT_OUT);
	if (type == T_HEREDOC)
		return (SYNTAX_ERR_HEREDOC);
	return (0);
}
*/
