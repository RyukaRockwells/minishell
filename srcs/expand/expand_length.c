/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:13:51 by nicole            #+#    #+#             */
/*   Updated: 2023/01/07 17:48:28 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_length_of_expand(char *str, int *i)
{
	(*i)++;
	while (ft_isalnum(str[(*i)]) == 1 || str[(*i)] == '_')
		(*i)++;
}

int	ft_strlen_contents_var(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
		{
			i++;
			length = ft_strlen(str + i);
			break ;
		}
		i++;
	}
	return (length);
}

int	ft_length_str_without_var(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			i++;
			while (ft_isalnum(str[i]) == 1 || str[i] == '_')
				i++;
		}
		else
		{
			i++;
			length++;
		}
	}
	return (length);
}

int	ft_strlen_var(t_data *data, char *str)
{
	int		i;
	int		length;
	char	*env;
	char	char_save;

	i = 0;
	env = "";
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			break ;
		i++;
	}
	char_save = str[i];
	str[i] = '\0';
	env = ft_getenv(data, str);
	if (env == NULL)
		env = str;
	str[i] = char_save;
	length = ft_strlen(env);
	if (str != env)
		free(env);
	return (length);
}

int	ft_length_all_content_var(t_data *data, char *str)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			length += ft_strlen_var(data, str + i + 1);
			i = ft_skip_name_var(str, i + 1);
		}
		else
			i++;
	}
	return (length);
}
