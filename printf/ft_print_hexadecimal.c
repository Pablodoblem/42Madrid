/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:18:27 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/04 18:14:29 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_char(char c)
{
	write(1, &c, 1);
}

void	write_string(const char *str)
{
	while (*str != '\0')
	{
		write_char(*str);
		str++;
	}
}

char	*transformtohexa(char *buffer, uintptr_t address, long divisor)
{
	int		digit;
	int		len;
	long	quotient;

	len = 2;
	while (divisor > 0)
	{
		quotient = address / divisor;
		digit = quotient % 16;
		if (digit < 10)
			buffer[len] = '0' + digit;
		else
			buffer[len] = 'a' + (digit - 10);
		len++;
		divisor /= 16;
	}
	buffer[len] = '\0';
	return (buffer);
}

int	print_hexadecimal(void *ptr)
{
	uintptr_t	address;
	char		buffer[20];
	long		divisor;

	if (!ptr)
		return (ft_write("(nil)"), 5);
	divisor = 1;
	address = (uintptr_t)ptr;
	while (address / divisor >= 16)
		divisor *= 16;
	buffer[0] = '0';
	buffer[1] = 'x';
	write_string(transformtohexa(buffer, address, divisor));
	write_char('\n');
	return (ft_strlen(buffer));
}
