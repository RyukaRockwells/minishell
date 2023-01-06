/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:10:19 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 19:12:57 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_msg_error_arg(char **str, t_data *data, char *lst_cmd)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(str[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	ft_free_all(data);
	ft_free_tab(data->envp);
	ft_free_tab(str);
	free(lst_cmd);
	exit(2);
}

int	ft_builtin_exit(char **str, t_data *data, char *lst_cmd)
{
	int	i;
	int	exit_code;

	i = 0;
	if (str[1] != NULL)
	{
		exit_code = ft_atoi(str[1]);
		if (str != NULL)
		{
			if (str[1][0] == '-' || str[1][0] == '+')
				i++;
			while (str[1][i] != '\0')
				if (ft_isdigit(str[1][++i]) == 0)
					ft_msg_error_arg(str, data, lst_cmd);
		}
		ft_free_tab(str);
		free(lst_cmd);
		fprintf(stderr, "number\n");
		exit(exit_code);
	}
	ft_free_tab(str);
	ft_free_all(data);
	ft_free_tab(data->envp);
	free(lst_cmd);
	fprintf(stderr, "code_exit\n");
	exit(data->code_exit);
}
