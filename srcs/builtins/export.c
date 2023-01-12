/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:54:56 by nchow-yu          #+#    #+#             */
/*   Updated: 2023/01/09 16:45:43 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_get_var_up_to_equals(char *str)
{
	char	*str_up_to_equals;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str_up_to_equals = malloc(sizeof(char) * ft_strlen_equal_var(str) + 2);
	if (str_up_to_equals == NULL)
		ft_exit(1);
	while (str[i] != '\0' && str[i] != '=')
		str_up_to_equals[j++] = str[i++];
	str_up_to_equals[j++] = str[i++];
	str_up_to_equals[j] = '\0';
	return (str_up_to_equals);
}

char	*ft_get_name_var(char *str)
{
	int		i;
	int		j;
	char	*name_var;

	i = 0;
	j = 0;
	name_var = malloc(sizeof(char) * ft_strlen_equal_var(str) + 2);
	if (name_var == NULL)
		ft_exit(1);
	while ((ft_isalnum(str[i]) == 1 || str[i] == '_') && str[i] != '\0')
		name_var[j++] = str[i++];
	name_var[j++] = str[i++];
	name_var[j] = '\0';
	return (name_var);
}

void	ft_modify_var_envp(t_data *data, char *var, char *name_var)
{
	int	i;
	int	length_var;

	i = 0;
	if (name_var[ft_strlen(name_var) - 1] == '=')
		length_var = ft_strlen(name_var) - 1;
	else
		length_var = ft_strlen(name_var);
	while (ft_strncmp(data->envp[i], name_var, length_var) != 0)
		i++;
	free(data->envp[i]);
	data->envp[i] = ft_strdup(var);
}

void	ft_add_var_in_envp(t_data *data, char *var)
{
	int		i;
	int		i_cpy;
	char	**envp;

	i = 0;
	i_cpy = 0;
	envp = malloc(sizeof(char *) * (ft_env_nbline(data->envp) + 2));
	if (envp == NULL)
		ft_exit(1);
	while (data->envp[i_cpy] != NULL)
		envp[i++] = ft_strdup(data->envp[i_cpy++]);
	envp[i++] = ft_strdup(var);
	envp[i] = NULL;
	ft_free_tab(data->envp);
	data->envp = envp;
}

int	ft_export(char **split_cmd, char **envp, t_data *data)
{
	char	*name_var;
	int		i;

	i = 1;
	(void)envp;
	if (split_cmd[1] == NULL)
	{
		ft_env(data);
		return (1);
	}
	while (split_cmd[i] != NULL)
	{
		name_var = ft_check_valid_var(split_cmd[i]);
		if (name_var == NULL)
			return (1);
		if (ft_verify_exist_var(data, name_var) == 1)
			ft_modify_var_envp(data, split_cmd[i], name_var);
		else
			ft_add_var_in_envp(data, split_cmd[i]);
		free(name_var);
		i++;
	}
	return (0);
}
