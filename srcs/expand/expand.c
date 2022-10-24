/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:28:10 by nicole            #+#    #+#             */
/*   Updated: 2022/10/24 16:31:53 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_replace_var(t_data *data, char ***str, int *i)
{
	char	*env;
	int		length;
	int		length_end;
	char	*tmp;
	int		j;

	env = "";
	(*i) += 1;
	length = ft_length_var(*i, (*(*str)), data);
	length_end = ft_length_end_var(length, (*(*str)));
	if (env == NULL)
		ft_exit(data);
	env = ft_get_var((*(*str)), *i, length);
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
