/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:08:32 by nicole            #+#    #+#             */
/*   Updated: 2022/10/24 16:35:44 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_length_var(int i, char *str, t_data *data)
{
	int		length;

	length = 0;
	if (getenv(str) == NULL)
	{
		ft_free_all(data);
		ft_exit(data);
	}
	while (str[i] != '\0' && str[i] != ' ')
	{
		i++;
		length++;
	}
	return (length);
}

int	ft_length_end_var(int length, char *str)
{
	int	length_end;

	length_end = 0;
	while (str[length] != '\0')
	{
		length++;
		length_end++;
	}
	return (length_end);
}

int	ft_get_last_id_var(char *str)
{
	int		last_id;

	last_id = 0;
	while (str[last_id] != '\0' && str[last_id] != ' ')
		last_id++;
	return (last_id);
}

char	*ft_get_var(char *str, int i, int length)
{
	char	*var;
	int		j;

	var = malloc(sizeof(char) * length + 1);
	j = 0;
	while (str[i] != '\0' && str[i] != ' ')
	{
		var[j] = str[i];
		j++;
		i++;
	}
	var[j] = '\0';
	return (var);
}
