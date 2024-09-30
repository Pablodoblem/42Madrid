/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoalarger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:53:29 by pamarti2          #+#    #+#             */
/*   Updated: 2024/09/29 20:45:12 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

unsigned long	count_digitslong(unsigned long n)
{
	unsigned long	counter;
	unsigned long	num;

	counter = 0;
	num = n;
	if (num == 0)
		return (counter = 1, counter);
	while (num != 0)
	{
		counter++;
		num /= 10;
	}
	//printf("VALOR NUM: %ld\n", n);
	//printf("counter DESDE ITOA: %ld\n", counter);
	return (counter);
}

char	*count_n_create_strr(unsigned long n)
{
	unsigned long	counter;
	char			*str;

	counter = count_digitslong(n);
	str = malloc((counter + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[counter] = '\0';
	return (str);
}

char	*write_with_conditionss(char *str, unsigned long i,
	unsigned long str_len, unsigned long number)
{
	unsigned long	z;
	unsigned long	x;

	z = 10;
	x = 1;
	while (str_len > 0)
	{
		if (str_len == 1)
		{
			while (number >= 10)
				number /= 10;
			str[i] = number + 48;
			return (str);
		}
		str[i] = (((number % z) / x) + 48);
		z *= 10;
		x *= 10;
		str_len--;
		i--;
	}
	return (str);
}

char	*ft_itoalarger(unsigned long n)
{
	char			*str;
	unsigned long	str_len;
	char			*str_zero;
	unsigned long	i;

	str_zero = "0";
	if (n > LONG_MAX)
		return (NULL);
	if (n == 0)
		return (str_zero);
	str = count_n_create_strr(n);
	str_len = count_digitslong(n);
	i = str_len - 1;
	str = write_with_conditionss(str, i, str_len, n);
	return (str);
}
