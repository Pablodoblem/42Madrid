/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:51:19 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/07 02:14:40 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	copy;

	copy = n;
	if (copy < 0)
	{
		copy *= -1;
		write(fd, "-", 1);
	}
	if (copy > 9)
	{
		ft_putnbr_fd(copy / 10, fd);
		ft_putchar_fd((copy % 10) + '0', fd);
	}
	else
		ft_putchar_fd(copy + '0', fd);
}

// int main(void)
// {
//   int n = -554;
//   ft_putnbr_fd(n, 2);
//   return (0);
// }
