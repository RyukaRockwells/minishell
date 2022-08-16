/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:10:38 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/08/16 19:50:18 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../srcs/libft/libft.h"

# define LITERAL 0
# define PIPE 1
# define REDIRECT_IN 2
# define REDIRECT_OUT 3
# define OR 4
# define AND 5

//struct a revoir

/*typedef struct s_list
{
	char	**arg;
	int		length;
	int		type;
	int		pipe[2];
	t_list	prev;
	t_list	next;
}				t_list;
*/
typedef struct s_token
{
	char	*value;
	int		type;
	t_token	*next;
}				t_token;
/*
typedef struct s_data
{
	char	*line;
	char	**arg;
	int		length;
	int		type;
	int		pipe[2];
	t_data	*prev;
}				t_data;
*/

//ft_deco.c
void	ft_deco(void);
//ft_error.c
void	ft_error(void);
//main.c
void	minishell(char **arg, char **envp);

#endif
