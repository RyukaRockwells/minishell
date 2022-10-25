/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:28:10 by nicole            #+#    #+#             */
/*   Updated: 2022/10/25 18:07:14 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_replace_var(char *str, int *i)
{
	char	*env;
	int		length;
	int		length_end;
	char	*tmp;
	int		j;

	env = "";
	(*i) += 1;
	length = ft_length_var(*i, str);
	length_end = ft_length_end_var(length, str);
	if (env == NULL)
		ft_exit();
	env = ft_get_var(str, *i, length);
	tmp = malloc(sizeof(char) * ft_strlen(getenv(env)) + length_end + 1);
	if (tmp == NULL)
		ft_exit();
	tmp = ft_strcpy(tmp, getenv(env));
	j = ft_strlen(getenv(env));
	length += 1;
	while (str[length] != '\0')
		tmp[j++] = str[length++];
	tmp[j] = '\0';
	free(env);
	return (tmp);
}

int	ft_exp_is_exist(char **str)
{
	char	*tmp;

	tmp = (*str) + 1;
	if (getenv(tmp) == NULL)
		return (0);
	return (1);
}

void	ft_expand_h(int fd, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '$')
		{
			if ((*str)[i + 1] == '?')
				write(fd, "error_code\n", 11);
			else if (ft_exp_is_exist(str) == 0)
				return ;
			else
			{
				tmp = ft_replace_var(*str, &i);
				free(*str);
				*str = tmp;
				return ;
			}
			
		}
		i++;
	}
}
