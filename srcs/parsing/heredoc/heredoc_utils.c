/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:43:30 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/02 17:45:39 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_rm_quotes(t_data *data, char **str)
{
	int	d_quotes;
	int	s_quotes;
	int	i;

	i = 0;
	d_quotes = 0;
	s_quotes = 0;
	while ((*str)[i] != '\0')
	{
		if (d_quotes != 0)
			d_quotes = ft_op_d_quotes(data, str, &i);
		else if (s_quotes != 0)
			s_quotes = ft_op_s_quotes(data, str, &i);
		else
		{
			if ((*str)[i] == '"')
				d_quotes = ft_cl_d_quotes(data, str, &i);
			else if ((*str)[i] == '\'')
				s_quotes = ft_cl_s_quotes(data, str, &i);
		}
	}
}

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
