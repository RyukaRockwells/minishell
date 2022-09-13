/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:09:25 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/09/13 21:09:03 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
//pour show_token comment free(word) dans lexer.c ligne 59
int	ft_get_cmd(t_data *data)
{
	int	error_status;

	error_status = ft_lexer(data);
	show_token(data);
	if (error_status != 0)
		return (error_status);
	error_status = ft_parser(data);
	if (error_status != 0)
		return (error_status);
	/*else
	{
		ft_tok(data);
	}*/
}
//crtl-d = agit que quand rdline est vide

void	ft_tok(t_data *data)
{
	t_token	*tmp;

	tmp = data->tok;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->next->type != LITERAL)
			return ;
		if (tmp->type == ESPACE)
			tmp = tmp->next;
		if (tmp->type == REDIRECT_IN || tmp->type == REDIRECT_OUT
			|| tmp->type == D_REDIRECT_OUT)
			tmp = ft_contoken(data, tmp);
		else if (tmp->type == LITERAL)
			tmp = ft_addtok(tmp->value, data, 10);
		else if (tmp->type == PIPE)
			tmp = ft_addtok(tmp->value, data, 11);
		printf("type = %d\n", tmp->type);
		printf("word = %s\n", tmp->word);
		tmp = tmp->next;
	}
}

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

*/
