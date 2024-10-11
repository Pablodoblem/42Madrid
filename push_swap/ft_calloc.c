/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:26:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/10 01:51:34 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_floatcalloc(size_t n, size_t size_of_element)
{
	float	*arr;
	int		i;

	i = 0;
	arr = malloc(n * size_of_element);
	if (arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	while (n > 0)
	{
		arr[i] = 0.5;
		n--;
		i++;
	}
	return (arr);
}
