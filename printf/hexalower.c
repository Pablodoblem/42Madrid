/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexalower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:42:47 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/28 19:06:11 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "printf.h"

int	contar_cifrass(int n)
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

char	*reverse_stringg(char *str)
{
	int		length;
	int		i;
	int		j;
	char	temp;

	i = 0;
	length = 0;
	j = length - 1;
	while (str[length] != '\0')
		length++;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

void	*hexalower(int num)
{
	char	*hex_digits;
	int		i;
	int		remainder;
	char	*hex_str;

	i = 0;
	hex_digits = "0123456789ABCDEF";
	hex_str = malloc(contar_cifrass(num) * sizeof(char));
	while (num != 0)
	{
		remainder = num % 16;
		if (remainder > 9)
			hex_str[i] = hex_digits[remainder] + 32;
		else
			hex_str[i] = hex_digits[remainder];
		i++;
		num /= 16;
	}
	ft_write(reverse_stringg(hex_str));
	return (hex_str);
}

// int	main(void)
// {
// 	int n = 2542352;
// 	hexalower(n);
// 	return (0);
// }