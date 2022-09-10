/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:27:21 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/08 17:01:28 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_parser(t_data *data)
{
	t_token	*list;
	int		error_status;

	list = data->token;
	error_status = ft_pre_check(list);
	if (error_status > 0)
		return (error_status);
	return (0);
}
