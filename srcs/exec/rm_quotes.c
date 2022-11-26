/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:46:06 by nicole            #+#    #+#             */
/*   Updated: 2022/11/26 16:56:28 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_length_str_without_quotes(char *str)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			i++;
		else
		{
			length++;
			i++;
		}
	}
	return (length);
}

char	*ft_rm_quotes(char	*str)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = malloc(sizeof(char) * ft_length_str_without_quotes(str) + 1);
	if (tmp == NULL)
		ft_exit();
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			i++;
		else
		{
			tmp[j] = str[i];
			j++;
			i++;
		}
	}
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

int	ft_strlen_before_hd(char *str)
{
	int	i;

	i = 0;
	while (str[i] != str[i + 1] && str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlen_after_hd(char *str)
{
	int	i;
	int	length;

	length = 0;
	i = ft_strlen_before_hd(str);
	while (str[i] == '<')
	{
		length++;
		i++;
	}
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

char	*ft_rm_heredoc_in_str(char *str)
{
	int		i;
	int		j;
	int		start;
	int		end;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	start = ft_strlen_before_hd(str);
	end = ft_strlen_after_hd(str);
	while (str[i] != '\0')
	{
		if (i >= start && i <= end)
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
