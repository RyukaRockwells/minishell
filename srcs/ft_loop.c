/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:09:25 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/10/01 19:07:49 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
//pour show_token comment free(word) dans lexer.c ligne 59

int	ft_get_cmd(t_data *data)
{
	int	error_status;

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
//crtl-d = agit que quand rdline est vide

void	ft_tok(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->next->type == ESPACE)
			tmp = tmp->next;
		if (tmp->type == ESPACE)
			tmp = tmp->next;
		if (tmp->type == REDIRECT_IN || tmp->type == REDIRECT_OUT
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
}

int	ft_chose_tok(t_data *data, char *value, int type)
{
	if (value == NULL || data == NULL)
		ft_exit(data);
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
	while (data->code_exit == 0)
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

/*
void	ft_group_tokens(t_data *data)
{
	t_token	*list;

	list = data->tokens_list;
	while (list)
	{
		if (!list->next && list->type != T_WORD)
			return ;
		if (list->type == T_SPACE)
			list = list->next;
		if (ft_is_redirect(list))
			list = ft_fill_redir_tkn(data, list);
		else if (list->type == T_WORD)
			ft_fill_new_token_2(list->value, data, T_CMD);
		else if (list->type == T_PIPE)
			ft_fill_new_token_2(list->value, data, T_PIPE);
		list = list->next;
	}
}

void	ft_fill_new_token_2(char *content, t_data *data, int type)
{
	t_token	*new_token;

	new_token = ft_new_token(data, content, type);
	ft_lstadd_back_token(&data->gp_tokens_list, new_token);
}

int	ft_get_redir_tkn(t_data *data, char *content, int type)
{
	if (!content || !data)
		ft_exit(data);
	if (type == T_REDIRECT_OUT)
		ft_fill_new_token_2(content, data, T_REDIRECT_OUT);
	if (type == T_REDIRECT_IN)
		ft_fill_new_token_2(content, data, T_REDIRECT_IN);
	if (type == T_HEREDOC)
		ft_fill_new_token_2(content, data, T_HEREDOC);
	if (type == D_REDIRECT_OUT)
		ft_fill_new_token_2(content, data, D_REDIRECT_OUT);
	return (0);
}

t_token	*ft_fill_redir_tkn(t_data *data, t_token *list)
{
	if (list->next->type != T_SPACE)
	{
		ft_get_redir_tkn(data, list->next->value, list->type);
		list = list->next;
	}
	else if (list->next->type == T_SPACE)
	{
		ft_get_redir_tkn(data, list->next->next->value, list->type);
		list = list->next->next;
	}
	return (list);
}


*/
