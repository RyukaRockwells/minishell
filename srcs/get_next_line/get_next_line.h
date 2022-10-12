/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:37:34 by nchow-yu          #+#    #+#             */
/*   Updated: 2022/02/03 11:58:07 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s);
char	*get_line(char *str);
char	*get_next_line(int fd);
char	*new_str(char *str);
char	*get_save(int fd, char *str);
char	*ft_free(char **str);

#endif

/*
get_save, nous permet  de recupere la ou les lignes et/ou le petit bout manquant de taille buffer_size
ce qui va nous donner le buffer (chaine de caractere) de taille buffer_size et non la ligne a afficher
join va fusionner str et le buff (str le reste save)

get_line, nous permet de recupere la premiere ligne du buffer_size, c'est a dire que l'on copie 
la premiere ligne jusqu'a soit "\n" soit "\0" et on retourne le resultat

new_str, va stocker le suite de la premiere ligne dans res depuis str
*/