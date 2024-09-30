/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexalower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:42:47 by pamarti2          #+#    #+#             */
/*   Updated: 2024/09/29 19:59:02 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

// int	count_digitshexalow(int n)
// {
// 	int	contador;
// 	int	num;

// 	contador = 0;
// 	num = n;
// 	while (num != 0)
// 	{
// 		contador++;
// 		num /= 10;
// 	}
// 	return (contador);
// }

char	*reverse_stringlower(char *str)
{
	int		length;
	int		i;
	int		j;
	char	temp;

	i = 0;
	length = 0;
	while (str[length] != '\0')
		length++;
	j = length - 1;
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

char	*calculate_hexa_str(int num, int rest, int flag, char *hex_str)
{
	char	*hex_digits;
	int		i;

	i = 0;
	if (flag == 1)
		hex_digits = "0123456789ABCDEF";
	else if (flag == 2)
		hex_digits = "0123456789abcdef";
	while (num != 0)
	{
		rest = num % 16;
		if (rest > 9)
			hex_str[i++] = hex_digits[rest] + 32;
		else
			hex_str[i++] = hex_digits[rest];
		num /= 16;
	}
	return (hex_str);
}

int	hexa(int num, int flag)
{
	int		i;
	int		rest;
	char	*hex_str;
	int		counter;

	i = ((rest = 0), num);
	if (num == 0)
		return (ft_write("0"), 1);
	while (i != 0)
	{
		i /= 16;
		rest++;
	}
	hex_str = malloc((rest + 1) * sizeof(char));
	if (!hex_str)
		return (0);
	hex_str[rest] = '\0';
	if (flag == 1)
		ft_write(reverse_stringlower
			(calculate_hexa_str(num, rest, 1, hex_str)));
	else if (flag == 2)
		ft_write(reverse_stringlower
			(calculate_hexa_str(num, rest, 2, hex_str)));
	counter = ft_strlen(hex_str);
	return (free(hex_str), counter);
}
