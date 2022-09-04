/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:01:35 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/04 23:26:05 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_pipe(t_token *tok)
{
	if (tok->next == NULL)
		return (PIPE_ERROR);
	if (tok->next->type == PIPE)
		return (PIPE_ERROR);
	if (tok->next == NULL && tok->type != LITERAL)
		return (PIPE_ERROR);
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
		if (error_code > 0)
			return (error_code);
		tmp = tmp->next;
	}
}
