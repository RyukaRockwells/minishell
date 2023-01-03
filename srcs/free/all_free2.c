/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:07:17 by nicole            #+#    #+#             */
/*   Updated: 2023/01/03 16:20:13 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_tab(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		free(envp[i]);
		envp[i] = NULL;
		i++;
	}
	free(envp);
}

void	ft_free_exe_simple(t_data *data, char **cmd, char *av)
{
	ft_free_token(data);
	ft_free_tok_exe(data);
	ft_free(cmd);
	ft_free(data->envp);
	free(data->readline);
	free(av);
}
