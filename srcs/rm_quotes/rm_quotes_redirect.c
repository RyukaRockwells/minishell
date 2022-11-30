/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:40:10 by nicole            #+#    #+#             */
/*   Updated: 2022/11/29 20:52:48 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


char	*ft_rm_str_tok_value(t_token *tok)
{
	t_token	*tmp;
	char	*new_str;

	tmp = tok;
	while (tmp->next != NULL)
	{
		if (tmp->type == REDIRECT_IN || tmp->type == REDIRECT_OUT
			|| tmp->type == D_REDIRECT_OUT)
			break ;
		else
			tmp = tmp->next;
	}
	new_str = ft_substr(tmp->next->value, 0, ft_strlen(tmp->next->value));
	return (ft_rm_quotes(new_str));
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
