/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:43:30 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/12 17:19:34 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_rm_quotes(t_data *data, char **str)
{
	int	d_quotes;
	int	s_quotes;
	int	i;

	d_quotes = 0;
	s_quotes = 0;
	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '\"' && s_quotes == 0)
			d_quotes++;
		if ((*str)[i] == '\'' && d_quotes == 0)
			s_quotes++;
		if ((*str)[i] == '\"' && s_quotes == 0 && d_quotes % 2 == 0)
			ft_strcpy(&(*str)[i], &(*str)[i + 1]);
		if ((*str)[i] == '\'' && d_quotes == 0 && s_quotes % 2 == 0)
			ft_strcpy(&(*str)[i], &(*str)[i + 1]);
		i++;
	}
}

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
