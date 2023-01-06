/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:23:19 by nicole            #+#    #+#             */
/*   Updated: 2023/01/05 01:34:23 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

//****-----------------****
//****-----BUILT-IN----****
//****-----------------****

//builtins/builtin.c
void	ft_builtin_no_fork(char **str, t_data *data, int is_hd);
int		ft_is_builtin(char **str);
int		ft_builtin(char **str, t_data *data);

//builtins/pwd.c
int		ft_pwd(void);

//builtins/cd.c
int		ft_cd(char **path_tab);

//builtins/env.c
int		ft_env(t_data *data);

//builtins/echo.c
int		ft_echo(char **tab_arg);

//builtins/exit.c
int		ft_builtin_exit(char **str, t_data *data);

//builtins/unset.c
int		ft_tablen(char **tab);
void	ft_replace_tab(t_data *data, int *i, int size);
int		ft_unset(t_data *data, char **var, int size);

//builtins/export.c
char	**ft_export2(char *var, char *str, char **envp);
int		ft_nb_equals(char *arg);
char	*ft_get_key(char *arg);
int		ft_key_is_upper(char *str);
int		ft_export(char **args, char **envp);

#endif
