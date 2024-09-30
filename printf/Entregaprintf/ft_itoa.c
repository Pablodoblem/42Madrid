/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:53:29 by pamarti2          #+#    #+#             */
/*   Updated: 2024/09/29 18:48:50 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int	count_digits(int n)
{
	int	counter;
	int	num;

	counter = 0;
	num = n;
	while (num != 0)
	{
		counter++;
		num /= 10;
	}
	return (counter);
}

char	*count_n_create_str(int n)
{
	int		counter;
	char	*str;

	counter = count_digits(n);
	if (n < 0)
	{
		counter++;
		str = malloc((counter + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '-';
	}
	else
	{
		str = malloc((counter + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
	}
	str[counter] = '\0';
	return (str);
}

char	*write_with_conditions(char *str, int i, int str_len, int number)
{
	int	z;
	int	x;

	z = 10;
	x = 1;
	while (str_len > 0 && i >= 0)
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

char	*ft_itoa(int n)
{
	char	*str;
	int		str_len;
	char	*str_limit_exception;
	char	*str_zero;
	int		i;

	str_limit_exception = "-2147483648";
	str_zero = "0";
	if (n == -2147483648)
		return (str_limit_exception);
	if (n == 0)
		return (str_zero);
	str = count_n_create_str(n);
	str_len = count_digits(n);
	i = str_len;
	if (n >= 0)
		i = str_len - 1;
	else
		n *= -1;
	str = write_with_conditions(str, i, str_len, n);
	return (str);
}
