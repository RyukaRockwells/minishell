/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:26:24 by nicole            #+#    #+#             */
/*   Updated: 2022/11/24 17:41:55 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

//****-----------------****
//****-----PRE_EXEC----****
//****-----------------****

//pre_exec/create_list.c
t_exe	*ft_create_list(int nb_pipe);
t_exe	*ft_new_exelst(void);
void	ft_fd_exec(t_data *data);
int		*ft_create_pipe(void);

//pre_exec/exe_list.c
t_exe	*ft_get_idexe(t_exe *exe, int i);
int		ft_nb_pipe(t_token *lst);
void	ft_exe_lst(t_data *data);
void	ft_addexe(t_exe **exe, t_exe *new);
t_exe	*ft_exelast(t_exe *exe);

//****-----------------****
//****------EXEC-------****
//****-----------------****

//pre_exec/rm_quotes.c
int		ft_length_str_without_quotes(char *str);
char	*ft_rm_quotes(char *str);
int		ft_strlen_after_hd(char *str);
int		ft_strlen_before_hd(char *str);
char	*ft_rm_heredoc_in_str(char *str);

//exec/exec.c
void	ft_exe_cmd(t_data *data);

//exec/exe_simple_cmd.c
void	ft_exe_cmd_simple(t_data *data);
void	execute(char *av, char **envp,t_data *data);

//exec/exe_utils.c
int		ft_is_heredoc(char *str);

//exec/exe_several_cmd.c
void	ft_exe_several_cmd(t_data *data);
void	first_pipe(t_data *data, int *fd_pipe, char *str);
void	mid_pipe(t_data *data, int *fd_pipe, char *str);
void	end_pipe(t_data *data, int *fd_pipe, char *str);

#endif
