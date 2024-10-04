/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 01:45:33 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/04 18:13:41 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(int num)
{
	char	*str;
	int		counter;

	if (num == 0 || num == -2147483648)
	{
		counter = ft_write(ft_itoa(num));
		return (counter);
	}
	str = ft_itoa(num);
	ft_write(str);
	counter = ft_strlen(str);
	free(str);
	return (counter);
}
