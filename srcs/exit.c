/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:28:52 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/23 16:04:58 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

/*
enlever le while et le close pour le remplacer dans
ft_free_token_list par close(tmp->fd);
ps: rajouter dans la structure token un :
int fd;
*/
void	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	ft_free(data->envp);//a bouger dans token_list
	free(data->readline);//idem
	while (i < 1024) /*Pourquoi 1024?*/
	{
		close(i);
		i++;
	}
	exit(0);
}

void	ft_free_token_list(t_data *data)
{
	t_token	*tok;
	t_token	*tok_exe;
	t_exe	*exe;

	//dprintf(2,"free token list\n");
	//printf("%p\n", data->token);
	while (data->token != NULL)
	{
		//dprintf(2,"TOKEN\n");
		tok = data->token;
		data->token = data->token->next;
		free(tok->value);
		tok->value = NULL;
		free(tok);
	}
	while (data->tok_exe != NULL)
	{
		//dprintf(2,"TOKEN\n");
		tok_exe = data->tok_exe;
		data->tok_exe = data->tok_exe->next;
		//free(tok_exe->value);
		tok_exe->value = NULL;
		free(tok_exe);
	}
	while (data->exe != NULL)
	{
		//dprintf(2,"TOKEN\n");
		exe = data->exe;
		data->exe = data->exe->next;
		//free(exe->value);
		exe->cmd[0] = NULL;
		free(exe);
	}
}
