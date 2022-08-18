/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:09:25 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/18 11:35:05 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_get_cmd(t_list *list)
{
	int	error_status;

	error_status = ft_lexer(list);
	if (error_status != 0)
		return (error_status);
	error_status = ft_parser(list);
}

void	ft_loop(t_list *list)
{
	int	code_error;

	code_error = 0;
	while (list->code_exit == 0)
	{
		ft_catch_signal();
		list->readline = readline("Minishell> ");//free(list->readline);
		if (list->readline != NULL)
			ft_catch_d(list);
		if (list->readline[0] != 0)
			add_history(list->readline);
		code_error = ft_get_cmd(list);
		else
			code_error = 1;
	}
}
