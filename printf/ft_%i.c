/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_%i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:07:20 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/04 18:13:20 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	powers(int str_len, int base)
{
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
		final_num += str[i] * powers(str_len, 8);
		i++;
		str_len--;
	}
	free (str);
	return (final_num);
}
