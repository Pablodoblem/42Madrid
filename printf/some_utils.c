/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:06:42 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/04 18:14:08 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
