/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:43:30 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/20 07:30:26 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_fdadd_back(t_fd **alst, t_fd *new)
{
	t_fd	*last_elmt;

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

t_fd	*ft_fdlast(t_fd *here_fd)
{
	if (here_fd != NULL)
	{
		while (here_fd->next != NULL)
			here_fd = here_fd->next;
	}
	return (here_fd);
}

void	ft_waitpid_h(t_data *data, int i)
{
	int	status;

	status = -1;
	waitpid(i, &status, 0);
	if (WIFEXITED(status))
		data->last_pipe = WEXITSTATUS(status);
	else
		data->last_pipe = status;
}