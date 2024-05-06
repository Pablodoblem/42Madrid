/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:56:33 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/15 14:38:28 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	contador;

	contador = 0;
	if (size != 0)
	{
		while (*src != '\0' && size > 1)
		{
			*dest = *src;
			dest++;
			src++;
			size--;
			contador += 1;
		}
		*dest = '\0';
	}
	while (*src != '\0')
	{
		src++;
		contador++;
	}
	return (contador);
}
