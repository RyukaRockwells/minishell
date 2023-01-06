/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:07:17 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 18:35:32 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void	ft_free_exe_simple(t_data *data, char **cmd, char *av)
{
	ft_free_token(data);
	ft_free_tok_exe(data);
	ft_free_tab(cmd);
	ft_free_tab(data->envp);
	free(data->readline);
	free(av);
}

void	ft_free_builtin(char *lst_cmd, char **tab_cmd)
{
	{
		free(lst_cmd);
		ft_free_tab(tab_cmd);
		ft_exit(1);
	}
}
