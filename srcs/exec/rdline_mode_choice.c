/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdline_mode_choice.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:36:40 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 16:55:45 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_rdline_choose(int is_hd, t_data *data, char *str)
{
	if (is_hd == 1)
		return (ft_rm_heredoc_in_str(data, str));
	else if (ft_is_rd(str) == 0)
		return (ft_is_redirect(str, data));
	else
		return (ft_expand(data, str));
}
