/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:13:51 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 22:40:01 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_length_of_expand(char *str, int *i)
{
	(*i)++;
	while (ft_isalnum(str[(*i)]) == 1 || str[(*i)] == '_')
		(*i)++;
}

void	ft_length_in_single_quote(char *str, int *i, int in_dquote, int *length)
{
	if (str[(*i)] == '\"' && in_dquote == 0)
		in_dquote = 1;
	else if (str[(*i)] == '\"' && in_dquote == 1)
		in_dquote = 0;
	if (str[(*i)] == '\'' && in_dquote == 0)
	{
		(*i)++;
		(*length)++;
		while (str[(*i)] != '\'')
		{
			(*i)++;
			(*length)++;
		}
		(*i)++;
		(*length)++;
	}
	else if (str[(*i)] == '$')
		ft_length_of_expand(str, &(*i));
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
		i++;
		length++;
	}
	return (length);
}

int	ft_strlen_var(char *str)
{
	int		i;
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
	env = getenv(str);
	if (env == NULL)
		env = str;
	str[i] = char_save;
	return (ft_strlen(env));
}

int	ft_length_all_content_var(char *str)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			length += ft_strlen_var(str + i + 1);
			i = ft_skip_name_var(str, i + 1);
		}
		else
			i++;
	}
	return (length);
}
