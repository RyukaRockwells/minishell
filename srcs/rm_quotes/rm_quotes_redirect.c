/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:40:10 by nicole            #+#    #+#             */
/*   Updated: 2023/01/10 02:02:58 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_get_first_redirect(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '>' || str[i] == '<'
			|| (str[i] == '>' && str[i + 1] == '>'))
		{
			i++;
			if (str[i] == '>')
				i++;
			while (ft_is_space(str[i]) == 0)
				i++;
			break ;
		}
		i++;
	}
	//if i == "\0"
	//	return -1;
	return (i);
}

char	*ft_get_file(t_data *data, char *str)
{
	// int		i;
	// char	*file;
	// char	char_save;

	// i = 0;
	//while(ligne)
	// {
	// i = ft_get_first_redirect(str);
	ft_open_all_file(data, str);
	// if (i == -1) means it didnt find any occurences of redirection
	//	break ;
	// while (ft_is_space(str[i]) == 0 && str[i] != '\0')
	// 	i++;
	// while (ft_is_space(str[i]) == 1 && str[i] != '\0')
	// 	i++;
	// char_save = str[i];
	// str[i] = '\0';
	// file = ft_expand(data, str + ft_get_first_redirect(str));
	// str[i] = char_save;
	// if (file[ft_strlen(file)] != '\0')
	// 	file[ft_strlen(file)] = '\0';
	//open_tmp_file
	//ft_rm_redirect_in_str
	//}
	// check if last_fd > 2
	//close(last fd)
	return (data->stmp); //returns last file found
}

int	ft_before_redirect(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<' && str[i + 1] != '<')
			break ;
		else if (str[i] == '>' && str[i + 1] != '>')
			break ;
		else if (str[i] == '>' && str[i + 1] == '>')
			break ;
		i++;
	}
	return (i);
}

int	ft_after_redirect(char *str)
{
	int	i;

	i = ft_get_first_redirect(str);
	while (ft_is_space(str[i]) == 0 && str[i] != '\0')
		i++;
	while (ft_is_space(str[i]) == 1 && str[i] != '\0')
		i++;
	return (i);
}

/*char	*ft_rm_redirect_in_str(t_data *data, char *str)
{
	int		i;
	int		j;
	char	*new_str;
	char	*str_exp;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (new_str == NULL)
		ft_exit(1);
	while (str[i] != '\0')
	{
		if (i >= ft_before_redirect(str) && i <= ft_after_redirect(str))
			new_str[j] = ' ';
		else
			new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	str_exp = ft_expand(data, new_str);
	free(new_str);
	return (str_exp);
}
*/

char	*ft_rm_redirect_in_str(t_data *data, char *str)
{
	int		i;
	int		j;
	char	*new_str;
	char	*str_exp;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (new_str == NULL)
		ft_exit(1);
	while (str[i] != '\0')
	{
		if (i >= ft_before_redirect(str) && i <= ft_after_redirect(str))
			new_str[j] = ' ';
		else
			new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	str_exp = ft_expand(data, new_str);
	free(new_str);
	return (str_exp);
}
