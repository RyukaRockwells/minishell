/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:40:06 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/19 19:00:40 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_lexer(t_data *data)
{
	int	i;
	int	status;

	status = ft_check_quotes(data->readline);
	if (status > 0)
		return (status);
}

int	ft_parser(t_data *data)
{
	return (0);
}
