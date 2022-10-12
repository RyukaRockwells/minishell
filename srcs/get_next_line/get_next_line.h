/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:37:34 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/06/05 16:08:06 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		gnl_strlen(char *s);
char	*ft_gnljoin(char *s1, char *s2);
int		ft_strline(char *s);
char	*get_line(char *str);
char	*get_next_line(int fd);
char	*new_str(char *str);
char	*get_save(int fd, char *str);
char	*gnl_free(char **str);

#endif
