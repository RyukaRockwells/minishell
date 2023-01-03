/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:40:10 by nicole            #+#    #+#             */
/*   Updated: 2023/01/03 14:47:42 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_get_file(t_data *data, char *str)
{
	int		i;
	char	*file;

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
			file = ft_expand(data, str + i);
		}
		i++;
	}
	i = 0;
	i = ft_skip_name_var(file, i);
	if (file[i] != '\0')
		file[i] = '\0';
	return (file);
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
	int	length;

	length = 0;
	i = ft_before_redirect(str);
	while (ft_is_space(str[i]) == 0)
	{
		length++;
		i++;
	}
	while ((str[i] != ' ' || ft_isascii(str[i]) == 1) && str[i] != '\0')
	{
		length++;
		i++;
	}
	return (i);
}

char	*ft_rm_redirect_in_str(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (new_str == NULL)
		ft_exit();
	while (str[i] != '\0')
	{
		if (i >= ft_before_redirect(str) && i <= ft_after_redirect(str))
			new_str[j] = ' ';
		else
		{
			new_str[j] = str[i];
		}
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
