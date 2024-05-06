/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:23:44 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/24 23:33:32 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ptr2coincidence(const char *haystack, const char *needle,
		size_t len, int contador3)
{
	int		contador;
	int		contador2;
	int		length;
	char	*aux;

	length = (int)len;
	contador2 = 0;
	contador = ft_strlen(needle);
	aux = (char *)haystack;
	while (*haystack == *needle)
	{
		if (contador3 == length)
			break ;
		contador2++;
		haystack++;
		contador3++;
		needle++;
		if (contador == contador2)
			return (aux);
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		contador;
	int		contador2;
	size_t	contador3;
	char	*aux;

	contador = ft_strlen(needle);
	contador2 = 0;
	contador3 = 0;
	if (*needle == '\0')
	{
		aux = (char *)haystack;
		return (aux);
	}
	while (*haystack != '\0' && len > 0)
	{
		if (*haystack == *needle)
			return (ptr2coincidence(haystack, needle, len, contador3));
		if (contador3 >= len && contador != contador2)
			break ;
		contador2 = 0;
		contador3++;
		haystack++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str1[] = "lorem ipsum dolor sit amet";
// 	char	str2[] = "ipsumm";

// 	printf("%s\n", ft_strnstr(str1, str2, 29));
// 	return (0);
// }
