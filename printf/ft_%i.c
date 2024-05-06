/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_%i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:07:20 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/28 01:22:07 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "printf.h"

int	exponencias(int str_len, int base)
{
	// int	x;

	// x = 1;
	while (str_len > 0)
	{
		base *= base;
		str_len--;
	}
	return (base);
}

int	octal(int n)
{
	char	*str;
	int		str_len;
	int		i;
	int		final_num;

	final_num = n;
	i = 1;
	str = ft_itoa(n);
	str_len = ft_strlen(str) - 2;
	while (str[i] != '\0' && str_len > 0 && i <= str_len + 1)
	{
		final_num += str[i] * exponencias(str_len, 8);
		i++;
		str_len--;
	}
	return (final_num);
}

int	main(void)
{
	int	n;

	n = 0x345;
	printf("%d", octal(n));
	return (0);
}