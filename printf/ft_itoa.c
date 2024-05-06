/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:53:29 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/27 13:33:04 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "printf.h"

int	contar_cifras(int n)
{
	int	contador;
	int	num;

	contador = 0;
	num = n;
	while (num != 0)
	{
		contador++;
		num /= 10;
	}
	return (contador);
}

char	*contar_cifras_y_crearstring(int n)
{
	int		contador;
	char	*str;

	contador = contar_cifras(n);
	if (n < 0)
	{
		contador++;
		str = malloc((contador + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '-';
	}
	else
	{
		str = malloc((contador + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
	}
	str[contador] = '\0';
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
	str = contar_cifras_y_crearstring(n);
	if (str == NULL)
		return (NULL);
	str_len = contar_cifras(n);
	i = str_len;
	if (n >= 0)
		i = str_len - 1;
	else
		n *= -1;
	str = write_with_conditions(str, i, str_len, n);
	return (str);
}

// int	main(void)
// {
// 	int	n = -2147483648;
// 	printf("%s\n", ft_itoa(n));
// 	return (0);
// } 