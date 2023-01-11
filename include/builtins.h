/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:23:19 by nicole            #+#    #+#             */
/*   Updated: 2023/01/11 18:38:52 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

//****-----------------****
//****-----BUILT-IN----****
//****-----------------****

//builtins/builtin.c
void	ft_builtin_no_fork(t_data *data, int is_hd, char *lst_cmd);
int		ft_is_builtin(char *lst_cmd);
int		ft_builtin(t_data *data, char *lst_cmd);

//builtins/pwd.c
int		ft_pwd(void);

//builtins/cd.c
int		ft_cd(char **path_tab);

//builtins/env.c
int		ft_env(t_data *data);

//builtins/echo.c
int		ft_echo(char **tab_arg);

//builtins/exit.c
int		ft_builtin_exit(char **str, t_data *data, char *lst_cmd);

//builtins/ft_unset.c
char	*get_key(char *str);
void	ft_unset_var(char *var_unset, t_data *data);
int		ft_unset(t_data *data, char **split_cmd);

//builtins/ft_export.c
char	*ft_get_var_up_to_equals(char *str);
char	*ft_get_name_var(char *str);
void	ft_modify_var_envp(t_data *data, char *var, char *name_var);
void	ft_add_var_in_envp(t_data *data, char *var);
int		ft_export(char **split_cmd, char **envp, t_data *data);

//builtins/utils.c
int		ft_verify_exist_var(t_data *data, char *name_var);
int		ft_strlen_name_var(char *s);
int		ft_strlen_equal_var(char *s);
char	*ft_check_valid_var(char *str);

#endif
