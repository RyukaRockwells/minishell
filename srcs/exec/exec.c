/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:41:32 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/25 18:30:01 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exe_cmd(t_data *data)
{
	if (data->nb_pipe == 0)
		ft_exe_cmd_simple(data);
	//else
	//	ft_exe_cmd_pipe(data);
	ft_free_all(data);
}
