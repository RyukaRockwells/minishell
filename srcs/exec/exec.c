/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:41:32 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/11/26 16:40:22 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exe_cmd(t_data *data)
{
	int	i;

	i = 0;
	while (data->readline[i] != '\0')
	{
		if (data->readline[i] == '<' && data->readline[i] == data->readline[i + 1])
			return ;
		if (data->readline[i] != ' ')
			break ;
		i++;
	}
	if (data->nb_pipe == 0)
	{
		if (ft_is_builtin(data->readline) == 1)
			ft_builtin(data->readline);
		else
			ft_exe_cmd_simple(data);
	}
	else if (data->nb_pipe > 0)
		ft_exe_several_cmd(data);
}
//ft_free_all(data);
