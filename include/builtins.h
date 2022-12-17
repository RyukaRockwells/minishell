/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:23:19 by nicole            #+#    #+#             */
/*   Updated: 2022/12/17 18:15:59 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

//****-----------------****
//****-----BUILT-IN----****
//****-----------------****
//builtins/echo.c
int		ft_option(char *str);
int		ft_echo_empty(char *str);
int		ft_echo(int ac, char **args);

//builtins/builtin.c'
int		ft_is_builtin(char *str, t_data *data);
int		ft_pwd(void);
int		ft_benv(t_data *data);
void	ft_print_env(t_data *data);
int		ft_builtin_exit(char *str, t_data *data);

#endif
