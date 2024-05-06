/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writehexaptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:33:32 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/14 02:28:54 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_writehexaptr(const void *ptr)
{
	uintptr_t	direccion;
	char		*buffer;
	char		*p;
	static const char	hex[] = "0123456789abcdef";
	int			i;

	i = sizeof(void*) * 2 - 1;
	buffer = malloc((sizeof(void*) * 2) + 3);
	p = buffer;
	*p++ = '0';
	*p++ = 'x';
	direccion = (uintptr_t)ptr;
	while (i >= 0)
	{
		*p++ = hex[(direccion >> (i * 4)) & 0xf];
		i--;
	}
	*p = '\n';
	write(STDOUT_FILENO, buffer, p - buffer);
}	