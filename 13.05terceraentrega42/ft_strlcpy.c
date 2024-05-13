/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:56:33 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/07 02:18:15 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	counter;

	counter = 0;
	if (size != 0)
	{
		while (*src != '\0' && size > 1)
		{
			*dest = *src;
			dest++;
			src++;
			size--;
			counter += 1;
		}
		*dest = '\0';
	}
	while (*src != '\0')
	{
		src++;
		counter++;
	}
	return (counter);
}
