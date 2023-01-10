/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdline_mode_choice.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:36:40 by nicole            #+#    #+#             */
/*   Updated: 2023/01/10 02:11:23 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	/*if (ft_is_metachar(str) == 0)
		return (NULL);
	if (ft_is_builtin(str) == 0)
	{
		
	}
	else
		return (ft_expand(data, str));*/
	if (is_hd == 1)
		return (ft_rm_heredoc_in_str(str));
	else if (ft_is_rd(str) == 0)
		return (ft_is_redirect(str, data));
	else
		return (ft_expand(data, str));
}
