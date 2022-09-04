/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:11:16 by nchow-yu          #+#    #+#             */
/*   Updated: 2021/11/26 16:12:46 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != 0 && i < size && size != 0)
		i++;
	while (src[j] != 0 && i < size - 1 && size != 0)
	{
		dst[i] = src[j];
		dst[i + 1] = 0;
		i++;
		j++;
	}
	while (src[j] != 0)
	{
		j++;
		i++;
	}
	return (i);
}
