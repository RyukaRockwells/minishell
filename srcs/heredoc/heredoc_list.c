/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:43:30 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/11 19:47:50 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_fdadd_back(t_here_fd **alst, t_here_fd *new)
{
	t_here_fd	*last_elmt;

	if (alst != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			last_elmt = ft_fdlast(*(alst));
			last_elmt->next = new;
		}
	}
}

t_here_fd	*ft_fdlast(t_here_fd *here_fd)
{
	if (here_fd != NULL)
	{
		while (here_fd->next != NULL)
			here_fd = here_fd->next;
	}
	return (here_fd);
}
