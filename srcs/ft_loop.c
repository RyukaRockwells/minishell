/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:09:25 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/12 18:46:20 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
//pour show_token comment free(word) dans lexer.c ligne 59
int	ft_get_cmd(t_data *data)
{
	int	error_status;

	error_status = ft_lexer(data);
	show_token(data);
	if (error_status != 0)
		return (error_status);
	error_status = ft_parser(data);
	if (error_status != 0)
		return (error_status);
	/*else
	{
		ft_tok(data);
	}*/
}
//crtl-d = agit que quand rdline est vide

void	ft_

void	ft_loop(t_data *data)
{
	int	code_error;

	code_error = 0;
	ft_deco();
	while (data->code_exit == 0)
	{
		ft_catch_signal();
		data->readline = readline("Minichouille> ");//free(data->readline);
		if (data->readline == NULL)
			ft_catch_d(data);
		if (data->readline[0] != 0)
			add_history(data->readline);
		code_error = ft_get_cmd(data);
		if (code_error != 0)
			show_error(code_error);
		ft_reinit(data);
	}
}
