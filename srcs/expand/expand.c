/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:28:10 by nicole            #+#    #+#             */
/*   Updated: 2023/01/08 23:24:04 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_replace_var_to_content(t_data *data, char *str, char *exp, int *j)
{
	int		i;
	int		k;
	char	*env;
	char	char_save;

	k = 0;
	i = ft_skip_name_var(str, 0);
	char_save = str[i];
	str[i] = '\0';
	env = ft_getenv(data, str);
	str[i] = char_save;
	i = 0;
	if (env == NULL)
		exp[(*j)++] = str[i++];
	while (env[k] != '\0')
	{
		exp[(*j)] = env[k];
		(*j)++;
		k++;
	}
	free(env);
}

int	ft_return_in_dquote(int d_quote_one, int d_quote_two, int pos)
{
	if (d_quote_one != d_quote_two
		&& (pos >= d_quote_one && pos <= d_quote_two))
		return (0);
	return (1);
}

int	ft_squote_not_in_dquote(char *str, int pos)
{
	int	i;
	int	d_quote_one;
	int	d_quote_two;
	int	in_quote;

	i = 0;
	in_quote = 0;
	d_quote_one = 0;
	d_quote_two = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"' && in_quote == 0)
		{
			in_quote = 1;
			d_quote_one = i;
		}
		else if (str[i] == '\"' && in_quote == 1)
		{
			d_quote_two = i;
			break ;
		}
		i++;
	}
	return (ft_return_in_dquote(d_quote_one, d_quote_two, pos));
}

void	ft_copy_single_quote(char *strexp, char *str, int *i, int *j)
{
	if (str[(*i)] == '\0')
		return ;
	if (str[(*i)] == '\'' && ft_nb_single_quote(str) >= 2
		&& ft_squote_not_in_dquote(str, (*i)) == 1)
	{
		strexp[(*j)++] = str[(*i)++];
		while (str[(*i)] != '\'')
			strexp[(*j)++] = str[(*i)++];
		strexp[(*j)++] = str[(*i)++];
	}
}

int	ft_nb_single_quote(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
			nb++;
		i++;
	}
	return (nb);
}
