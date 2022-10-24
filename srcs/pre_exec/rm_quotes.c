/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:46:06 by nicole            #+#    #+#             */
/*   Updated: 2022/10/24 15:32:28 by nicole           ###   ########.fr       */
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

char	*ft_rm_quotes(t_data *data)
{
	char	*tmp;
	char	*str;
	int		i;
	int		j;

	str = data->readline;
	tmp = malloc(sizeof(char) * ft_length_str_without_quotes(str) + 1);
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
	return (tmp);
}

int	ft_length_each_part(t_data *data)
{
	int		i;
	t_token	*tmp;
	
	i = 1;
	tmp = data->token;
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	*ft_remove_quotes(char	*str)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = malloc(sizeof(char) * ft_length_str_without_quotes(str));
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
	return (tmp);
}
//demander jerem pour la condition de la boucle while

void	ft_rm_quotes_token(t_data *data)
{
	char	**cmd;
	t_token	*tok;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	cmd = malloc(sizeof(char *) * ft_length_each_part(data));
	tok = data->token;
	while (tok->value || tok->next != NULL)
	{
		cmd[j] = ft_remove_quotes(tok->value);
		j++;
		tok = tok->next;
	}
}
