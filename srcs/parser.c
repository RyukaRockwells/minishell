/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:01:35 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/04 12:10:54 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_parser(t_data *data)
{
	t_token	*tmp;
	int		error_code;

	tmp = data->token;
	error_code = ft_pre_check(tmp);
	if (error_code > 0)
		return (error_code);
}
