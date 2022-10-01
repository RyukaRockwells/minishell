/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:01:35 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/01 16:06:48 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_pipe(t_token *tok)
{
	t_token	*tmp;
	int		word;

	word = 0;
	tmp = tok;
	if (tmp->next == NULL)
		return (PIPE_ERROR);
	if (tmp->next->type == PIPE)
		return (PIPE_ERROR);
	if (tmp->next == NULL && tmp->type != LITERAL)
		return (PIPE_ERROR);
	while (tmp->next != NULL)
	{
		if (tmp->next->type == LITERAL)
			word = 1;
		if (tmp->next->type == PIPE && word < 1)
			return (PIPE_ERROR);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_heredoc(t_data *data, t_token *tok)
{
	if (tok->next->type == ESPACE)
	{
		if (tok->next->next == NULL)
			return (NEWLINE_ERROR);
		if (tok->next->next->type == HEREDOC)
			return (HEREDOC_ERROR);
		if (tok->next->next->type == PIPE)
			return (PIPE_ERROR);
		if (ft_check_heredoc(data, tok->next->next) == EXIT_HEREDOC)
			return (EXIT_HEREDOC);
	}
	else
	{
		if (tok->next->type != LITERAL)
			return (HEREDOC_ERROR);
		if (ft_check_heredoc(data, tok->next) == EXIT_HEREDOC)
			return (EXIT_HEREDOC);
	}
	return (0);
}

//heredoc a completer
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
			error_code = ft_heredoc(data, tmp);
		}
		if (error_code > 0)
			return (error_code);
		tmp = tmp->next;
	}
	return (0);
}
