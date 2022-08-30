/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:20:13 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/30 19:07:30 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//get_quotes sunny
int	ft_get_token(t_data *data, char *rdline, int i, int strlen)
{
	char	*wd;

	wd = ft_substr(rdline, i, strlen);
	if (wd == NULL)
		ft_exit(data);
	//free(wd);
	ft_add_token(wd, data, LITERAL);
	return (0);
}
