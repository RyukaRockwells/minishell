/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:28:10 by nicole            #+#    #+#             */
/*   Updated: 2022/10/13 19:05:36 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_expand_token(t_data *data, t_token *tok)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tok->value[i] != '\0')
	{
		if (tok->value[i] == '\'')
			j = 1 - j;
		if (tok->value[i] == '$' && j != 0)
		{
			if (tok->value[i + 1] == '?')
				ft_expand_pipe(data, &tok->value, &i);
			else
				ft_expand_pipe(data, &tok->value, &i);
		}
		i++;
	}
}

void	ft_expand_pipe(t_data *data, char **str, int *i)
{
	char	*tmp;

	ft_rm_str(data, str, 2, *i);
	tmp = ft_itoa(data->last_pipe);
	if (tmp == NULL)
		ft_exit(data);
}

void	ft_expand_h(t_data *data, char **str)
{
	int	i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '$')
		{
			if ((*str)[i + 1] == '?')
				ft_expand_pipe(data, str, &i);
			else
				ft_expand_pipe(data, str, &i);
		}
		i++;
	}
}
