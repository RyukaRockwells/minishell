/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:22:57 by nicole            #+#    #+#             */
/*   Updated: 2023/01/07 15:48:36 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

//****-----------------****
//****------EXPAND-----****
//****-----------------****
//expand/expand.c
void	ft_replace_var_to_content(t_data *data, char *str, char *exp, int *j);
int		ft_exp_is_exist(t_data *data, char *str);

//expand/expand_utils.c
int		ft_length_name_var(int i, char *str);
int		ft_length_end_var(int length, char *str);
int		ft_get_last_id_var(char *str);
char	*ft_get_var(char *str, int i, int length);
int		ft_skip_name_var(char *str, int i);

//expand/expand_type.c
void	ft_expand_exit(t_data *data, char *strexp, int *i, int *j);
char	*ft_expand_h(t_data *data, char *str);
char	*ft_expand(t_data *data, char *str);

//expand/expand_length.c
void	ft_length_of_expand(char *str, int *i);
int		ft_strlen_contents_var(char *str);
int		ft_length_str_without_var(char *str);
int		ft_strlen_var(t_data *data, char *str);
int		ft_length_all_content_var(t_data *data, char *str);

//expand/translate_expand.c
char	*ft_getenv(t_data *data, char *str);
void	ft_translate_expand(t_data *data, char *str, char *strexp);

#endif
