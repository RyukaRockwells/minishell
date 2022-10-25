/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:26:24 by nicole            #+#    #+#             */
/*   Updated: 2022/10/25 16:56:46 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

//****-----------------****
//****-----PRE_EXEC----****
//****-----------------****

//pre_exec/create_list.c
t_exe	*ft_create_list(t_data *data, int nb_pipe);
t_exe	*ft_new_exelst(t_data *data);
void	ft_fd_exec(t_data *data);
int		*ft_create_pipe(t_data *data);

//pre_exec/exe_list.c
t_exe	*ft_get_idexe(t_exe *exe, int i);
int		ft_nb_pipe(t_token *lst);
void	ft_exe_lst(t_data *data);
t_exe	ft_addexe(t_exe **exe, t_exe *new);
t_exe	*ft_exelast(t_exe *exe);

//pre_exec/check_exe.c
void	ft_check_cmd_redirect(t_data *data);
t_fd	*ft_fd_heredoc(t_data *data, int i);

//pre_exec/add_exe.c
void	ft_add_exe_h(t_data *data, int i);
void	ft_add_exe_cmd(t_data *data, t_token *tok_exe, int i);

//pre_exec/rm_quotes.c
char	*ft_rm_quotes(t_data *data);
void	ft_rm_quotes_token(t_data *data);

//****-----------------****
//****------EXEC-------****
//****-----------------****

//exec/exec.c
void	ft_exe_cmd(t_data *data);

//exec/exe_simple_cmd.c
void	ft_exe_cmd_simple(t_data *data);
void	execute(char *av, char **envp);

#endif
