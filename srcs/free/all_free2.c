/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:07:17 by nicole            #+#    #+#             */
/*   Updated: 2022/11/26 16:24:37 by nicole           ###   ########.fr       */
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
	ft_free_exe(data);
	ft_free(data->envp);
	ft_free(cmd);
	free(av);
}
