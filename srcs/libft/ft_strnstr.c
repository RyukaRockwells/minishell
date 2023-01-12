/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:08:30 by nchow-yu          #+#    #+#             */
/*   Updated: 2021/11/26 18:13:34 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	letter;

	i = 0;
	if (little[0] == '\0' || little == NULL)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		letter = 0;
		while (little[letter] == big[i + letter] && i + letter < len)
		{
			if (little[letter + 1] == '\0')
				return ((char *)big + i);
			letter++;
		}
		i++;
	}
	return (NULL);
}
