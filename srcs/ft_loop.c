/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanauth <sanauth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:09:25 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/04 20:51:11 by sanauth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_get_cmd(t_data *data)
{
	int	error_status;

	error_status = ft_lexer(data);
	//show_token(data);
	if (error_status != 0)
		return (error_status);
	error_status = ft_parser(data);
	if (error_status != 0)
		return (error_status);
}
//crtl-d = agit que quand rdline est vide

void	ft_loop(t_data *data)
{
	int	code_error;

	code_error = 0;
	ft_deco();
	while (data->code_exit == 0)
	{
		ft_catch_signal();
		data->readline = readline("Minichouille> ");//free(data->readline);
		if (data->readline == NULL)
			ft_catch_d(data);
		if (data->readline[0] != 0)
			add_history(data->readline);
		code_error = ft_get_cmd(data);
		if (code_error != 0)
			show_error(code_error);
		ft_reinit(data);
	}
}

/*
**	ft_check_quotes :
int	quotes_not_close(void)
{
	int		i;

	i = 0;
	while (g_data.input[i])
	{
		if (g_data.input[i] == '\'')
		{
			i++;
			while (g_data.input[i] && g_data.input[i] != '\'')
				i++;
			if (g_data.input[i] != '\'')
				return (1);
		}
		if (g_data.input[i] == '\"')
		{
			i++;
			while (g_data.input[i] && g_data.input[i] != '\"')
				i++;
			if (g_data.input[i] != '\"')
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_get_separators(t_data *data, int index)
{
	char	*separator;
	char	*line;

	line = data->read_line;
	if (ft_is_space_sep(line[index]) == 0)
		ft_is_space(data, line, index);
	if (line[index] == '<' || line[index] == '>')
	{
		ft_is_redirect(data, line, index);
		if (ft_is_double_redirect(line, index, line[index]))
			return (1);
	}
	if (line[index] == '|')
	{
		separator = ft_substr(line, index, 1);
		if (!separator)
			ft_exit(data);
		ft_add_to_garbage_collector(data, separator);
		ft_fill_new_token(separator, data, T_PIPE);
	}
	return (0);
}

int	ft_get_word(t_data *data, int index)
{
	char	*word_token;
	char	*line;

	line = data->read_line;
	if (line[index] == '\'' || line[index] == '\"')
	{
		if (ft_check_no_space(line, index, line[index]))
		{
			ft_get_mixed_token(data, line, index, ft_word_len(line, index));
			return (ft_word_len(line, index));
		}
	}
	if (line[index] >= 33 && line[index] <= 126 && ft_is_word(line, index))
	{
		word_token = ft_substr(line, index, ft_word_len(line, index));
		if (!word_token)
			ft_exit(data);
		ft_add_to_garbage_collector(data, word_token);
		ft_fill_new_token(word_token, data, T_WORD);
		return (ft_word_len(line, index));
	}
	return (0);
}

int	ft_is_word(char *line, int index)
{
	if (line[index] == '<' || line[index] == '>'
		|| line[index] == '|'
		|| ft_is_space_sep(line[index]) == 0)
		return (0);
	return (1);
}

void	ft_fill_new_token(char *content, t_data *data, int type)
{
	t_token	*new_token;

	new_token = ft_new_token(data, content, type);
	ft_lstadd_back_token(&data->tokens_data, new_token);
}

**	ft_is_space :
int	ft_is_space_sep(char c)
{
	if (c == '\t' || c == '\v'
		|| c == '\n' || c == '\r'
		|| c == '\f' || c == '\r'
		|| c == ' ')
		return (0);
	return (1);
}

int	ft_fill_tokens_data(t_data *data)
{
	size_t	index;
	int		statut;

	statut = ft_check_unclose_quote(data->read_line);
	if (statut > 0)
		return (UNCLOSED_QUOTES_ERR);
	index = 0;
	while (index < ft_strlen(data->read_line))
	{
		index += ft_get_word(data, index);
		index += ft_get_separators(data, index);
		index++;
	}
	return (0);
}

int	ft_check_no_space(char *line, int index, char c)
{
	int	i;

	i = 0;
	index++;
	while (line[index] != c)
	{
		index++;
		i++;
	}
	if (line[index + 1] == '\0')
		return (0);
	if (ft_is_word(line, index + 1))
		return (1);
	else
		return (0);
}

int	ft_get_mixed_token(t_data *data, char *read_line, int index, int len)
{
	char	*word;

	word = ft_substr(read_line, index, len);
	if (!word)
		ft_exit(data);
	ft_add_to_garbage_collector(data, word);
	ft_fill_new_token(word, data, T_WORD);
	return (0);
}
*/
