/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:41:32 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/11/24 16:10:01 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exe_cmd(t_data *data)
{
	if (data->nb_pipe == 0)
	{
		if (ft_is_builtin(data->readline) == 1)
			ft_builtin(data->readline);
		else
			ft_exe_cmd_simple(data);
	}
	else
		ft_exe_several_cmd(data);
	//ft_free_all(data);
}
