/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:54:18 by pamarti2          #+#    #+#             */
/*   Updated: 2024/12/22 20:45:49 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	spaces_sign_and_createnumber(char *str_char, int i,
	int number, int sign)
{
	while (str_char[i] == '-' || str_char[i] == '+')
	{
		if ((str_char[i] == '-' || str_char[i] == '+')
			&& (str_char[i + 1] == '+' || str_char[i + 1] == '-'))
			return (0);
		else if (str_char[i] == '-')
		{
			i++;
			sign = -1;
		}
		else
			i++;
	}
	if (str_char[i] >= '0' && str_char[i] <= '9')
	{
		while (str_char[i] >= '0' && str_char[i] <= '9')
		{
			number = number * 10 + (str_char[i] - '0');
			i++;
		}
	}
	return (number * sign);
}

int	ft_atoi(char *str)
{
	int		number;
	int		sign;
	int		i;
	char	*str_char;

	str_char = (char *)str;
	i = 0;
	number = 0;
	sign = 1;
	while (str_char[i] != '\0')
	{
		while (str_char[i] == '\n' || str_char[i] == ' '
			|| str_char[i] == '\f' || str_char[i] == '\t'
			|| str_char[i] == '\v' || str_char[i] == '\r')
			i++;
		return (spaces_sign_and_createnumber(str_char, i, number, sign));
	}
	return (spaces_sign_and_createnumber(str_char, i, number, sign));
}
