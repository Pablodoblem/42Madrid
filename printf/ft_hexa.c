/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:42:47 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/04 19:37:06 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	condition(int num, int i, int j)
{
	int					*binary;
	int					*bininv;
	int					*placed_binary;
	int					rest;
	unsigned long		result;

	binary = ft_calloc(32, sizeof(int));
	placed_binary = ft_calloc(32, sizeof(int));
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

char	*reverse_string(char *str)
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
	return (reverse_string(hex_str));
}

int	manage_cases(int num)
{
	int	i;
	int	rest;

	i = ((rest = 0), num);
	if (num == 0) //revisar con dicion. Tener en cuenta en la función hexa
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
	return (rest);
}

int	hexa(int num, int flag)
{
	int		rest;
	char	*hex_str;
	int		counter;
	char	*aux;

	rest = manage_cases(num);
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
