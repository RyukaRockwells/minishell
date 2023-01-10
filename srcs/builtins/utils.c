/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:05:24 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/09 16:35:38 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_verify_exist_var(t_data *data, char *name_var)
{
	int	i;
	int	length_var;

	i = 0;
	if (name_var[ft_strlen(name_var) - 1] == '=')
		length_var = ft_strlen(name_var) - 1;
	else
		length_var = ft_strlen(name_var);
	while (data->envp[i] != NULL)
	{
		if (ft_strncmp(data->envp[i], name_var, length_var) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_equal_var(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '=')
		i++;
	return (i);
}

int	ft_strlen_name_var(char *s)
{
	int	i;

	i = 0;
	while ((ft_isalnum(s[i]) == 1 || s[i] == '_') && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_check_valid_var(char *str)
{
	char	*name_without_condition;
	char	*name_with_condition;

	name_without_condition = ft_get_var_up_to_equals(str);
	name_with_condition = ft_get_name_var(str);
	if (ft_strcmp(name_without_condition, name_with_condition) != 0)
	{
		ft_putstr_fd("minishell: export: not an identifier\n", 2);
		free(name_with_condition);
		free(name_without_condition);
		return (NULL);
	}
	free(name_without_condition);
	return (name_with_condition);
}
