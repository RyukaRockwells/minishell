/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:34:29 by nicole            #+#    #+#             */
/*   Updated: 2022/12/31 13:04:52 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
int	display_expand(char *str)
{
	int	i;
	int	show;

	i = 0;
	show = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
			{
				if (str[i] == '$')
					show = 1;
				i++;
			}
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"')
			{
				if (str[i] == '$')
					show = 2;
				i++;
			}
		}
		i++;
	}
	return (show);
}

int	main(void)
{
	int	show;

	show = display_expand("bonjour \"un peu beau  coup\" \'$pas du tout\'");
	if (show == 1)
		fprintf(stderr, "Single quote!\n");
	else if (show == 2)
		fprintf(stderr, "Double quote!\n");
	else
		fprintf(stderr, "No expand!\n");
}
*/
