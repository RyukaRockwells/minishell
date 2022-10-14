/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:28:10 by nicole            #+#    #+#             */
/*   Updated: 2022/10/14 20:58:40 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*
void	ft_expand_token(t_data *data, t_token *tok)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tok->value[i] != '\0')
	{
		if (tok->value[i] == '\'')
			j = 1 - j;
		if (tok->value[i] == '$' && j != 0)
		{
			if (tok->value[i + 1] == '?')
				ft_expand_pipe(data, &tok->value, &i);
			else
				ft_expand_pipe(data, &tok->value, &i);
		}
		i++;
	}
}

void	ft_expand_pipe(t_data *data, char **str, int *i)
{
	char	*tmp;

	ft_rm_str(data, str, 2, *i);
	tmp = ft_itoa(data->last_pipe);
	if (tmp == NULL)
		ft_exit(data);
}
*/

char	*ft_replace_var(t_data *data, char ***str, int *i)
{
	char	*env;
	int		length;
	int		length_end;
	char	*tmp;
	int		j;

	env = "";
	(*i) += 1;
	length = ft_length_var(*i, (*(*str)));
	length_end = ft_length_end_var(length, (*(*str)));
	if (env == NULL)
		ft_exit(data);
	env = ft_get_var((*(*str)), *i, length);
	printf("%s = %s\n", env, getenv(env));
	tmp = malloc(sizeof(char) * ft_strlen(getenv(env)) + length_end + 1);
	if (tmp == NULL)
		ft_exit(data);
	tmp = ft_strcpy(tmp, getenv(env));
	j = ft_strlen(getenv(env));
	length += 1;
	while ((*(*str))[length] != '\0')
		tmp[j++] = (*(*str))[length++];
	tmp[j] = '\0';
	free(env);
	return (tmp);
}

void	ft_expand_h(int fd, t_data *data, char **str)
{
	int		i;
	char	**show;
	char	*new_str;

	i = 0;
	new_str = NULL;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '$')
		{
			if ((*str)[i + 1] == '?')
				write(fd, "error_code\n", 11);
			else
			{
				(*str) = ft_replace_var(data, &str, &i);
				return ;
			}
		}
		i++;
	}
}
