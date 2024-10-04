/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:42:47 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/03 13:42:56 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

char	*ft_toupper(char *str)
{
	char	*auxstr;
	int		i;

	i = 0;
	auxstr = malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 120)
			auxstr[i] = str[i] - 32;
		else
			auxstr[i] = str[i];
		i++;
	}
	auxstr[i] = '\0';
	return (auxstr);
}

unsigned long	bnry_to_dec(int *binary, int length)
{
	unsigned long	result;
	unsigned long	power;
	int				i;

	i = length - 1;
	result = ((power = 1), 0);
	while (i >= 0)
	{
		if (binary[i] == 1)
			result += power;
		power *= 2;
		i--;
	}
	return (result);
}

int	*inversion(int *binary)
{
	int	*bininv;
	int	i;

	i = 0;
	bininv = malloc(32 * sizeof(int));
	while (i < 32)
	{
		if (binary[i] == 0)
			bininv[i] = 1;
		else
			bininv[i] = 0;
		i++;
	}
	return (bininv);
}

unsigned long	condition(int num, int i, int j)
{
	int					*binary;
	int					*bininv;
	int					*placed_binary;
	int					rest;
	unsigned long		result;

	binary = calloc(32, sizeof(int));
	placed_binary = calloc(32, sizeof(int));
	num *= -1;
	num--;
	while (num > 0)
	{
		binary[i++] = num % 2;
		num /= 2;
	}
	rest = i;
	i = 0;
	while (i < rest)
		placed_binary[j--] = binary[i++];
	bininv = inversion(placed_binary);
	result = bnry_to_dec(bininv, 32);
	free(bininv);
	free(binary);
	free(placed_binary);
	return (result);
}

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

char	*calculate_hexa_str(int num, int rest, char *hex_str)
{
	char				*hex_digits;
	int					i;
	int					j;
	unsigned long		realnum;

	i = 0;
	j = 31;
	realnum = num;
	if (num < 0)
		realnum = condition(num, i, j);
	hex_digits = "0123456789ABCDEF";
	while (realnum != 0)
	{
		rest = realnum % 16;
		if (rest > 9)
			hex_str[i++] = hex_digits[rest] + 32;
		else
			hex_str[i++] = hex_digits[rest];
		realnum /= 16;
	}
	hex_str[i] = '\0';
	return (reverse_stringlower(hex_str));
}

int	hexa(int num, int flag)
{
	int		i;
	int		rest;
	char	*hex_str;
	int		counter;
	char	*aux;

	i = ((rest = 0), num);
	if (num == 0)
		return (ft_write("0"), 1);
	if (num > 0)
	{
		while (i != 0)
		{
			i /= 16;
			rest++;
		}
	}
	else
		rest = 8;
	hex_str = malloc((rest + 1) * sizeof(char));
	if (!hex_str)
		return (0);
	hex_str[rest] = '\0';
	if (flag == 1)
		ft_write((calculate_hexa_str(num, rest, hex_str)));
	else if (flag == 2)
	{
		aux = ft_toupper((calculate_hexa_str(num, rest, hex_str)));
		ft_write(aux);
		free(aux);
	}
	counter = ft_strlen(hex_str);
	return (free(hex_str), counter);
}
