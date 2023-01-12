/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdline_mode_choice.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:36:40 by nicole            #+#    #+#             */
/*   Updated: 2023/01/12 11:01:31 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_rd(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp != NULL)
	{
		if (tmp->type == REDIRECT_IN || tmp->type == REDIRECT_OUT
			|| tmp->type == D_REDIRECT_OUT)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_is_metachar(char *str)
{
	int	i;

	i = 0;
	while (ft_is_space(str[i]) == 0)
		i++;
	if (str[i] == '\\' || str[i] == ';')
		return (0);
	return (1);
}

char	*ft_rdline_choose(int is_hd, t_data *data, char *str)
{
	char	*lst_cmd;

	lst_cmd = str;
	if (is_hd == 1)
		lst_cmd = ft_rm_heredoc_in_str(lst_cmd);
	if (ft_is_rd(data) == 1)
		lst_cmd = ft_is_redirect(lst_cmd, data);
	else
		lst_cmd = ft_expand(data, lst_cmd);
	return (lst_cmd);
}
