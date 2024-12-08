/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:26:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/12/08 23:51:54 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_floatcalloc(size_t n, size_t size_of_element)
{
	float	*arr;
	int		i;

	i = 0;
	if (n == 0 || size_of_element == 0)
		return (NULL);
	arr = malloc(n * size_of_element);
	if (arr == NULL)
		return (NULL);
	while (i < (int)n)
	{
		arr[i] = 0.5;
		i++;
	}
	return (arr);
}
