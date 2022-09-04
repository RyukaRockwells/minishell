/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchow-yu <nchow-yu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:50:46 by nchow-yu          #+#    #+#             */
/*   Updated: 2021/11/29 17:57:48 by nchow-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb1;

	nb1 = n;
	if (nb1 < 0)
	{
		ft_putchar_fd('-', fd);
		nb1 = nb1 *(-1);
	}
	if (nb1 < 10)
		ft_putchar_fd(nb1 + '0', fd);
	else
	{
		ft_putnbr_fd(nb1 / 10, fd);
		ft_putnbr_fd(nb1 % 10, fd);
	}
}
