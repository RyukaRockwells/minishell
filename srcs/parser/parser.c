/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:01:35 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/11 18:07:52 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pipe(t_token *tok)
{
	if (tok->next == NULL)
		return (PIPE_ERROR);
	if (tok->next->type == PIPE)
		return (PIPE_ERROR);
	if (tok->next == NULL && tok->type != LITERAL)
		return (PIPE_ERROR);
}

int	ft_heredoc(t_token *tok)
{
	if (tok->next->type == ESPACE)
	{
		if (tok->next->next == NULL)
			return (NEWLINE_ERROR);
		if (tok->next->next->type == HEREDOC)
			return (HEREDOC_ERROR);
		if (tok->next->next->type == PIPE)
			return (PIPE_ERROR);
	}
	else
	{
		if (tok->next->type != LITERAL)
			return (HEREDOC_ERROR);
	}
	return (0);
}

int	ft_parser(t_data *data)
{
	t_token	*tmp;
	int		error_code;

	tmp = data->token;
	error_code = ft_pre_check(tmp);
	if (error_code > 0)
		return (error_code);
	while (tmp != NULL)
	{
		if (tmp->type == PIPE)
			error_code = ft_pipe(tmp);
		if (tmp->type == REDIRECT_IN || tmp->type == REDIRECT_OUT
			|| tmp->type == D_REDIRECT_OUT)
			error_code = ft_check_redirect(tmp);
		if (tmp->type == HEREDOC)
		{
			if (tmp->next == NULL)
				return (HEREDOC_ERROR);
			error_code = ft_heredoc(tmp);
		}
		if (error_code > 0)
			return (error_code);
		tmp = tmp->next;
	}
	return (0);
}
