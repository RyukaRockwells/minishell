/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:39:03 by nicole            #+#    #+#             */
/*   Updated: 2023/01/04 20:40:35 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_expand_exit(t_data *data, char *strexp, int *i, int *j)
{
	char	*code_error;
	int		k;

	code_error = ft_itoa(data->code_exit);
	k = 0;
	(*i)++;
	while (code_error[k] != '\0')
			strexp[(*j)++] = code_error[k++];
	free(code_error);
}

char	*ft_expand_h(t_data *data, char *str)
{
	int		length_all_content;
	int		length_without_var;
	char	*strexp;

	length_all_content = ft_length_all_content_var(str);
	length_without_var = ft_length_str_without_var(str);
	strexp = malloc(sizeof(char) * length_all_content + length_without_var + 1);
	if (strexp == NULL)
		ft_exit(1);
	ft_translate_expand(data, str, strexp);
	free(str);
	return (strexp);
}

char	*ft_expand(t_data *data, char *str)
{
	int		length_all_content;
	int		length_without_var;
	char	*strexp;

	length_all_content = ft_length_all_content_var(str);
	length_without_var = ft_length_str_without_var(str);
	strexp = malloc(sizeof(char) * length_all_content + length_without_var + 1);
	if (strexp == NULL)
		ft_exit(1);
	ft_translate_expand(data, str, strexp);
	return (strexp);
}
