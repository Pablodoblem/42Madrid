/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:56:52 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/04 18:13:51 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	unsigned_num(unsigned int num)
{
	size_t	counter;
	char	*str;

	counter = 0;
	if (num == 0)
	{
		counter = ft_write(ft_itoalarger(num));
		return (counter);
	}
	str = ft_itoalarger(num);
	ft_write(str);
	free (str);
	counter = (count_digitslong(num));
	return (counter);
}
