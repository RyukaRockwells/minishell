/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:28:10 by nicole            #+#    #+#             */
/*   Updated: 2022/12/11 17:44:00 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*replace_var = remplacer les noms de var env par sa valeur
*/

int	ft_length_str_without_var(char *str)
{
	int	i;
	int	length;
	int	ignore;

	i = 0;
	ignore = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			ignore = 1;
		}
		else if (str[i] == ' ')
			ignore = 0;
		if (ignore == 0)
		{
			length++;
		}
		i++;
	}
	return (length);
}

int	ft_strlen_var(char *str)
{
	int		i;
	char	*env;
	char	char_save;

	i = 0;
	env = "";
	while (str[i] != '\0')
	{
		if (str[i] == '$' || ft_is_space(str[i]) == 0)
			break ;
		i++;
	}
	char_save = str[i];
	str[i] = '\0';
	env = getenv(str);
	str[i] = char_save;
	return (ft_strlen(env));
}

int	ft_length_all_content_var(char *str)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			length += ft_strlen_var(str + i + 1);
		i++;
	}
	return (length);
}

void	ft_replace_var_to_content(char *str, char *strexp, int	*next_i, int *next_j)
{
	int		j;
	int		start_env;
	char	*env;
	char	char_save;

	j = 0;
	env = "";
	start_env = (*next_i);
	while (str[(*next_i)] != '\0')
	{
		while ((str[(*next_i)] != '$' && ft_is_space(str[(*next_i)]) != 0) && str[(*next_i + 1)] != '\0')
			(*next_i)++;
		break ;
	}
	if (str[(*next_i + 1)] == '\0')
		(*next_i)++;
	char_save = str[(*next_i)];
	str[(*next_i)] = '\0';
	env = getenv(str + start_env);
	str[(*next_i)] = char_save;
	while (env[j] != '\0')
	{
		strexp[(*next_j)] = env[j];
		(*next_j)++;
		j++;
	}
}

void	ft_replace_expand(char *str, char *strexp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			i++;
			ft_replace_var_to_content(str, strexp, &i, &j);
		}
		else
		{
			strexp[j] = str[i];
			i++;
			j++;
		}
	}
	strexp[j] = '\0';
}

char	*ft_replace_var(char *str, int *i)
{
	char	*env;
	int		length;
	int		length_end;
	char	*tmp;
	int		j;

	env = "";
	(*i) += 1;
	length = ft_length_name_var(*i, str);
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

int	ft_exp_is_exist(char *str)
{
	char	*tmp;
	int		i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '$')
			break ;
		i++;
	}
	tmp = malloc(sizeof(char) * i + 1);
	if (tmp == NULL)
		ft_exit();
	ft_strlcpy(tmp, str + 1, i);
	if (getenv(tmp) == NULL)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int	ft_is_expand(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == '?')
				write(fd, "error_code\n", 11);
			else if (ft_exp_is_exist(str + i) == 1)
			{
				return (1);
			}
			else
				return (0);
		}
		i++;
	}
	return (0);
}

char	*ft_expand_h(int fd, char *str)
{
	int		length_all_content;
	int		length_without_var;
	char	*strexp;

	if (ft_is_expand(fd, str) == 0)
		return (str);
	length_all_content = ft_length_all_content_var(str);
	length_without_var = ft_length_str_without_var(str);
	strexp = malloc(sizeof(char) * length_all_content + length_without_var + 1);
	if (strexp == NULL)
		ft_exit();
	ft_replace_expand(str, strexp);
	free(str);
	return (strexp);
}

char	*ft_expand(char *str)
{
	int		length_all_content;
	int		length_without_var;
	char	*strexp;

	if (ft_is_expand(2, str) == 0)
		return (str);
	length_all_content = ft_length_all_content_var(str);
	length_without_var = ft_length_str_without_var(str);
	strexp = malloc(sizeof(char) * length_all_content + length_without_var + 1);
	if (strexp == NULL)
		ft_exit();
	ft_replace_expand(str, strexp);
	return (strexp);
}
