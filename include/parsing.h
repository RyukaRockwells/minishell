/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:22:14 by nicole            #+#    #+#             */
/*   Updated: 2022/10/25 18:01:59 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//****-----------------****
//****------LEXER------****
//****-----------------****

//lexer/lexer.c
int		ft_lexer(t_data *data);
int		ft_parser(t_data *data);
int		ft_get_word(t_data *data, int i);
int		ft_get_sep(t_data *data, int i);
int		ft_word_quote(char *str, int i, char c);

//lexer/lexer_utils.c
int		ft_is_space(char c);
int		ft_is_separator(char c);
int		ft_wdlen(char *str, int i);
int		ft_add_space(t_data *data, char *str, int i);
void	ft_redirect(t_data *data, char *str, int i);

//lexer/lexer_check.c
int		ft_check_metachar(char *str, int i);
int		ft_check_quotes(char *str);
void	ft_check_squotes(char *str, int *i, int *j);
void	ft_check_dquotes(char *str, int *i, int *j);

//****-----------------****
//****------TOKEN------****
//****-----------------****

//token/token.c
int		ft_get_token(t_data *data, char *rdline, int i, int strlen);
void	ft_add_token(char *word, t_data *data, int type);
void	ft_addtok(char *word, t_data *data, int type);

//token/token_list.c
void	ft_tokenadd_back(t_token **tok, t_token *new);
t_token	*ft_tokenlast(t_token *tok);

//****-----------------****
//****------PARSER-----****
//****-----------------****

//parser/parser2.c
int		ft_pipe(t_token *tok);
int		ft_parser(t_data *data);

//parser/parser_check2.c
int		ft_empty_tok(t_token *tok);
int		ft_pre_check(t_token *tok);
int		ft_check_redirect(t_token *tmp);
int		ft_check_next_tok(int type);

#endif
