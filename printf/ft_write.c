/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 23:49:55 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/04 18:13:58 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(const char *str)
{
	int	counter;

	if (!str)
	{
		ft_write("(null)");
		counter = 6;
		return (counter);
	}
	counter = 0;
	while (*str != '\0')
	{
		write (1, str, 1);
		str++;
		counter++;
	}
	return (counter);
}
