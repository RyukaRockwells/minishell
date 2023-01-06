/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:09:25 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/06 22:19:02 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_get_cmd(t_data *data)
{
	int	error_status;
	int	i;

	i = ft_strlen(data->readline) - 1;
	while (data->readline[i] == ' ')
		i--;
	data->readline[i + 1] = '\0';
	error_status = ft_lexer(data);
	if (error_status != 0)
		return (error_status);
	error_status = ft_parser(data);
	if (error_status != 0)
		return (error_status);
	else
	{
		ft_tok(data);
		ft_exe_lst(data);
	}
	return (0);
}

void	ft_tok(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->next->type == ESPACE)
			tmp = tmp->next;
		else if (tmp->type == ESPACE)
			tmp = tmp->next;
		else if (tmp->type == REDIRECT_IN || tmp->type == REDIRECT_OUT
			|| tmp->type == D_REDIRECT_OUT)
			tmp = ft_sep_redtok(data, tmp);
		else if (tmp->type == LITERAL)
			ft_addtok(tmp->value, data, CMD);
		else if (tmp->type == PIPE)
			ft_addtok(tmp->value, data, PIPE);
		tmp = tmp->next;
	}
}

t_token	*ft_sep_redtok(t_data *data, t_token *tmp)
{
	if (tmp->next->type != ESPACE)
	{
		ft_chose_tok(data, tmp->next->value, tmp->type);
		tmp = tmp->next;
	}
	else if (tmp->next->type == ESPACE)
	{
		ft_chose_tok(data, tmp->next->next->value, tmp->type);
		tmp = tmp->next->next;
	}
	return (tmp);
}

int	ft_chose_tok(t_data *data, char *value, int type)
{
	if (value == NULL || data == NULL)
		ft_exit(data->code_exit);
	if (type == REDIRECT_IN)
		ft_addtok(value, data, REDIRECT_IN);
	else if (type == REDIRECT_OUT)
		ft_addtok(value, data, REDIRECT_OUT);
	else if (type == D_REDIRECT_OUT)
		ft_addtok(value, data, D_REDIRECT_OUT);
	else if (type == HEREDOC)
		ft_addtok(value, data, HEREDOC);
	return (0);
}

void	ft_loop(t_data *data)
{
	int	code_error;

	code_error = 0;
	ft_deco();
	while (1)
	{
		ft_catch_signal();
		data->readline = readline("Minichouille> ");
		if (data->readline == NULL)
			ft_catch_d(data);
		if (data->readline[0] != 0)
			add_history(data->readline);
		code_error = ft_get_cmd(data);
		if (code_error != 0)
			show_error(code_error);
		else
			ft_exe_cmd(data);
		ft_reinit(data);
	}
}
