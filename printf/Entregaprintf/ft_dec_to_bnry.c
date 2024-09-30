/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_bnry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:56:52 by pamarti2          #+#    #+#             */
/*   Updated: 2024/09/29 20:51:18 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	bnry_to_dec(int *binary, int length)
{
	unsigned long	result;
	unsigned long	power;
	int				i;
	char			*str;

	i = length - 1;
	result = ((power = 1), 0);
	while (i >= 0)
	{
		if (binary[i] == 1)
			result += power;
		power *= 2;
		i--;
	}
	str = ft_itoalarger(result);
	ft_write(str);
	return (free (str), count_digitslong(result));
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

// int	condition(unsigned int num, int counter, int i, int j)
// {
// 	int	*binary;
// 	int	*bininv;
// 	int	*placed_binary;
// 	int	rest;

// 	binary = calloc(32, sizeof(int));
// 	placed_binary = calloc(32, sizeof(int));
// 	num *= -1;
// 	num--;
// 	while (num > 0)
// 	{
// 		rest = num % 2;
// 		binary[i++] = rest;
// 		num /= 2;
// 	}
// 	rest = ((i = 0), i);
// 	while (i < rest)
// 		placed_binary[j--] = binary[i++];
// 	counter = ((bininv = inversion(placed_binary)), bnry_to_dec(bininv, 32));
// 	free(bininv);
// 	free(binary);
// 	free(placed_binary);
// 	return (counter);
// }

size_t	dec_to_bnry(unsigned int num)
{
	//int	i;
	//int	j;
	size_t	counter;

	//i = 0;
	//j = 31;
	counter = 0;
	// if (num < 0)
	// 	counter = condition(num, counter, i, j);
	// else
	// {
		//counter = ft_write(ft_itoalarger(num));
		//printf("\nCOUNTER DESDE DEC2BNRY: %d\n", counter);
		counter = (count_digitslong(num) - 1);
	//}
	return (counter);
}
