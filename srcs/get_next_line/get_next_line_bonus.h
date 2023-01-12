/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicole <nicole@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:09:42 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/11/26 14:45:09 by nicole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *s);
char	*get_line(char *str);
char	*get_next_line(int fd);
char	*new_str(char *str);
char	*get_save(int fd, char *str);
char	*ft_free_gnl(char **str);
int		check_size(int size, char *save, char *str);

#endif
