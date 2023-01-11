/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:43:30 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/10 14:40:20 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_heredoc(char *str)
{
	int		i;
	int		return_hd;
	char	quote;

	i = 0;
	return_hd = 0;
	quote = 0;
	while (str[i] != '\0')
	{
		if (str[i] == quote)
			quote = 0;
		else if ((str[i] == '\'' || str[i] == '\"') && quote == 0)
			quote = str[i];
		else if (str[i] == '<' && str[i + 1] == '<' && quote != 0)
			return_hd = 0;
		else if (str[i] == '<' && str[i + 1] == '<' && quote == 0)
			return_hd = 1;
		i++;
	}
	return (return_hd);
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
