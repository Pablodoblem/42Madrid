/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:19:08 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/15 14:36:48 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	char	*str;

	str = (char *)ptr;
	while (*str != '\0' && num > 0)
	{
		if (*str == value)
			return (str);
		str++;
		num--;
	}
	return (NULL);
}

/*
int	main() 
{
    const char	*str = "Hello, world!";
    char		target = 'j';
	const char	*str2 = "Hello, world!";
    char		target2 = 'j';

    // Buscar la primera ocurrencia de 'w' en str
    const char	*result = memchr(str, target, strlen(str));
	const char	*result2 = ft_memchr(str2, target2, strlen(str2));

    if (result != NULL) {
        printf("Se encontró '%c' en la posición %ld\n", target, result - str);
    } else {
        printf("'%c' no se encontró en la cadena.\n", target);
    }
	printf("%s\n", result);
	if (result2 != NULL) {
        printf("Se encontró '%c' en la posición %ld\n", target2, result2 - str2);
    } else {
        printf("'%c' no se encontró en la cadena.\n", target2);
    }
	printf("%s\n", result2);

    return 0;
}
*/