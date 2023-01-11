/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:24:31 by nicole            #+#    #+#             */
/*   Updated: 2023/01/11 12:17:10 by nchow-yu         ###   ########.fr       */
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
	int			file_exit;
	char		*readline;
	char		**envp;
	int			last_pipe;
	int			nb_pipe;
	t_token		*token;
	t_token		*tok_exe;
	int			fd_out;
	int			fd_in;
	int			last_fd;
	int			type_in;
	int			type_out;
	int			type_dout;
	char		*file_in;
	char		*file_out;
	char		*stmp;
}				t_data;

#endif
