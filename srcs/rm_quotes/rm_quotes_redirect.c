/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:40:10 by nicole            #+#    #+#             */
/*   Updated: 2023/01/11 12:28:26 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_get_first_redirect(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '>' || str[i] == '<'
			|| (str[i] == '>' && str[i + 1] == '>'))
		{
			i++;
			if (str[i] == '>')
				i++;
			while (ft_is_space(str[i]) == 0)
				i++;
			break ;
		}
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int	ft_before_redirect(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<' && str[i + 1] != '<')
			break ;
		else if (str[i] == '>' && str[i + 1] != '>')
			break ;
		else if (str[i] == '>' && str[i + 1] == '>')
			break ;
		i++;
	}
	return (i);
}

int	ft_after_redirect(char *str)
{
	int	i;

	i = ft_get_first_redirect(str);
	while (ft_is_space(str[i]) == 0 && str[i] != '\0')
		i++;
	while (ft_is_space(str[i]) == 1 && str[i] != '\0')
		i++;
	return (i);
}
