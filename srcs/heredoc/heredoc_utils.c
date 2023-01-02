/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:43:30 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/12/28 18:10:02 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_heredoc(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<' && str[i] == str[i + 1])
			return (1);
		i++;
	}
	return (0);
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
