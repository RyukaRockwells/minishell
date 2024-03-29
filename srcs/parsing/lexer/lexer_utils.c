/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:53:35 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/10 11:41:10 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (0);
	return (1);
}

int	ft_is_separator(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (0);
	return (1);
}

int	ft_wdlen(char *str, int i)
{	
	int	j;

	j = 0;
	while (str[i] != '\0')
	{
		if (ft_check_metachar(str, i) == 0)
			return (j);
		if (str[i] == 34)
			ft_check_dquotes(str, &i, &j);
		if (str[i] == 39)
			ft_check_squotes(str, &i, &j);
		if (ft_check_metachar(str, i) == 0)
			if (str[i] == '\0')
				return (j);
		j++;
		i++;
	}
	return (j);
}

int	ft_add_space(t_data *data, char *str, int i)
{
	char	*tok_space;

	if (ft_is_space(str[i] == 1) && i == 0)
	{
		tok_space = ft_substr(str, i, 1);
		if (tok_space == NULL)
			ft_exit(1);
		ft_add_token(tok_space, data, ESPACE);
		return (0);
	}
	if (ft_is_space(str[i] == 1) && ft_is_space(str[i - 1]) == 0)
	{
		tok_space = ft_substr(str, i, 1);
		if (tok_space == NULL)
			ft_exit(1);
		ft_add_token(tok_space, data, ESPACE);
		return (0);
	}
	return (0);
}

void	ft_redirect(t_data *data, char *str, int i)
{
	char	*sep;

	if (str[i + 1] == str[i])
	{
		sep = ft_substr(str, i, 2);
		if (sep == NULL)
			ft_exit(1);
		if (str[i] == '>')
			ft_add_token(sep, data, D_REDIRECT_OUT);
		else if (str[i] == '<')
			ft_add_token(sep, data, HEREDOC);
	}
	else
	{
		sep = ft_substr(str, i, 1);
		if (sep == NULL)
			ft_exit(1);
		if (str[i] == '<')
			ft_add_token(sep, data, REDIRECT_IN);
		else if (str[i] == '>')
			ft_add_token(sep, data, REDIRECT_OUT);
	}
}
