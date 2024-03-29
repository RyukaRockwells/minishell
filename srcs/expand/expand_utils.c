/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:08:32 by nicole            #+#    #+#             */
/*   Updated: 2023/01/03 17:17:09 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_length_name_var(int i, char *str)
{
	int		length;

	length = 0;
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
	if (var == NULL)
		ft_exit(1);
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

int	ft_skip_name_var(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			break ;
		i++;
	}
	return (i);
}
