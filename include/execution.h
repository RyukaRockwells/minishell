/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:26:24 by nicole            #+#    #+#             */
/*   Updated: 2023/01/06 18:47:00 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

//****-----------------****
//****-----PRE_EXEC----****
//****-----------------****

//pre_exec/exe_list.c
int		ft_nb_pipe(t_token *lst);
void	ft_exe_lst(t_data *data);

//****-----------------****
//****------EXEC-------****
//****-----------------****

//exec/exec.c
void	ft_exe_cmd(t_data *data);
void	ft_choose_fd(int is_hd, t_data *data, char *str);
void	execute(char *av, char **envp, t_data *data);

//exec/exe_simple_cmd.c
void	ft_exe_simple_cmd(t_data *data);

//exec/exe_utils.c
void	close_and_wait_process(t_data *data, int *fd_pipe, char **cmd_pipe);
void	check_path_null(char *tab_path, char *cmd, char **path);
void	check_opath_null(char *tab_path, char *o_path, char *cmd, char **path);
void	ft_set_code_exit(t_data *data, int status);

//exec/exe_several_cmd.c
void	ft_exe_several_cmd(t_data *data);
void	first_process(t_data *data, char **tab_cmd, int *fd_pipe, char *str);
void	mid_process(t_data *data, int i, int *fd_pipe, char **tab_cmd);
void	end_process(t_data *data, char **tab_cmd, int *fd_pipe, char *str);
void	redirect_process(t_data *data, char **cmd_pipe, int *fd_pipe);

//exec/rdline_mode_choice.c
char	*ft_rdline_choose(int is_hd, t_data *data, char *str);

//****-----------------****
//****----REDIRECT-----****
//****-----------------****

//redirect/redirect.c
int		ft_is_rd(char *str);
int		ft_is_rd_in(char *str);
int		ft_is_rd_out(char *str);
int		ft_type_of_redirect(char *str);
char	*ft_is_redirect(char *str, t_data *data);

//****-----------------****
//****----RM_QUOTE-----****
//****-----------------****

int		ft_length_str_without_quotes(char *str);
int		ft_strlen_after_hd(char *str);
int		ft_strlen_before_hd(char *str);
char	*ft_rm_heredoc_in_str(t_data *data, char *str);

char	*ft_get_file(t_data *data, char *str);
int		ft_before_redirect(char *str);
int		ft_after_redirect(char *str);
char	*ft_rm_redirect_in_str(t_data *data, char *str);

#endif
