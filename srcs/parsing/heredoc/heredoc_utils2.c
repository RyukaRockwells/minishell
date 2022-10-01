/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:38:34 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/01 18:02:35 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_op_d_quotes(t_data *data, char **str, int *i)
{
	if ((*str)[*i] == '"')
	{
		ft_rm_str(data, str, 1, *i);
		(*i)--;
		return (0);
	}
	return (1);
}

int	ft_op_s_quotes(t_data *data, char **str, int *i)
{
	if ((*str)[*i] == '\'')
	{
		ft_rm_str(data, str, 1, *i);
		(*i)--;
		return (0);
	}
	return (1);
}

int	ft_cl_d_quotes(t_data *data, char **str, int *i)
{
	ft_rm_str(data, str, 1, *i);
	(*i)--;
	return (1);
}

int	ft_cl_s_quotes(t_data *data, char **str, int *i)
{
	ft_rm_str(data, str, 1, *i);
	(*i)--;
	return (1);
}

void	ft_rm_str(t_data *data, char **str, int len, int i)
{
	int		size;
	char	*new_str;
	int		j;
	int		k;

	size = ft_strlen(*str);
	new_str = (char *)malloc(sizeof(char) * (size + 1));
	if (new_str == NULL)
		ft_exit(data);
	if (i > (int)ft_strlen(*str))
		i = ft_strlen(*str);
	j = 0;
	while (j < i)
	{
		new_str[j] = (*str)[j];
		j++;
	}
	k = i;
	while ((*str)[k] != '\0' && k - i < len)
		k++;
	while ((*str)[k] != '\0')
		new_str[j++] = (*str)[k++];
	new_str[j] = '\0';
	ft_free_token(data);
	*str = new_str;
}
