/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:24:31 by nicole            #+#    #+#             */
/*   Updated: 2023/01/03 14:28:19 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

//struct a revoir

typedef struct s_token		t_token;
typedef struct s_data		t_data;

typedef struct s_token
{
	char	*value;
	int		type;
	t_token	*next;
}				t_token;

typedef struct s_data
{
	int			code_exit;
	char		*readline;
	char		**envp;
	int			last_pipe;
	int			nb_pipe;
	t_token		*token;
	t_token		*tok_exe;
	int			fd_stdout;
	int			fd_stdin;
	int			last_fd;
}				t_data;

#endif
