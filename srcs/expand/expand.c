/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:28:10 by nicole            #+#    #+#             */
/*   Updated: 2023/01/02 21:00:00 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_length_str_without_var(char *str)
{
	int	i;
	int	length;
	int	in_dquote;

	i = 0;
	in_dquote = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"' && in_dquote == 0)
			in_dquote = 1;
		else if (str[i] == '\"' && in_dquote == 1)
			in_dquote = 0;
		if (str[i] == '\'' && in_dquote == 0)
		{
			i++;
			length++;
			while (str[i] != '\'')
			{
				i++;
				length++;
			}
			i++;
			length++;
		}
		else if (str[i] == '$')
		{
			i++;
			while (ft_isalnum(str[i]) == 1 || str[i] == '_')
				i++;
		}
		else
		{
			i++;
			length++;
		}
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
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			break ;
		i++;
	}
	char_save = str[i];
	str[i] = '\0';
	env = getenv(str);
	if (env == NULL)
		env = str;
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
		{
			length += ft_strlen_var(str + i + 1);
			i = ft_skip_name_var(str, i + 1);
		}
		else
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
		while (ft_isalnum(str[(*next_i)]) == 1 || str[(*next_i)] == '_')
			(*next_i)++;
		break ;
	}
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

void	ft_replace_expand(int fd, char *str, char *strexp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
		{
			strexp[j++] = str[i++];
			while (str[i] != '\'')
				strexp[j++] = str[i++];
			strexp[j++] = str[i++];
		}
		else if (str[i] == '\"')
		{
			strexp[j++] = str[i++];
			while (str[i] != '\"')
			{
				if (str[i] == '$')
				{
					i++;
					if (str[i] == '?')
						write(fd, "error_code\n", 11);
					else if (ft_exp_is_exist(str + i) != 0)
					{
						while (ft_isalnum(str[i]) == 1 || str[i] == '_')
							i++;
					}
					else
						ft_replace_var_to_content(str, strexp, &i, &j);
				}
				else
					strexp[j++] = str[i++];
			}
			strexp[j++] = str[i++];
		}
		else if (str[i] == '$')
		{
			i++;
			if (str[i] == '?')
				write(fd, "error_code\n", 11);
			else if (ft_exp_is_exist(str + i) != 0)
			{
				while (ft_isalnum(str[i]) == 1 || str[i] == '_')
					i++;
			}
			else
				ft_replace_var_to_content(str, strexp, &i, &j);
		}
		else
			strexp[j++] = str[i++];
	}
	strexp[j] = '\0';
}

int	ft_exp_is_exist(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			break ;
		i++;
	}
	tmp = malloc(sizeof(char) * i + 1);
	if (tmp == NULL)
		ft_exit();
	ft_strlcpy(tmp, str, i + 1);
	if (getenv(tmp) == NULL)
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

char	*ft_expand_h(int fd, char *str)
{
	int		length_all_content;
	int		length_without_var;
	char	*strexp;

	length_all_content = ft_length_all_content_var(str);
	length_without_var = ft_length_str_without_var(str);
	strexp = malloc(sizeof(char) * length_all_content + length_without_var + 1);
	if (strexp == NULL)
		ft_exit();
	ft_replace_expand(fd, str, strexp);
	free(str);
	return (strexp);
}

char	*ft_expand(char *str)
{
	int		length_all_content;
	int		length_without_var;
	char	*strexp;

	length_all_content = ft_length_all_content_var(str);
	length_without_var = ft_length_str_without_var(str);
	strexp = malloc(sizeof(char) * length_all_content + length_without_var + 1);
	if (strexp == NULL)
		ft_exit();
	ft_replace_expand(2, str, strexp);
	return (strexp);
}
