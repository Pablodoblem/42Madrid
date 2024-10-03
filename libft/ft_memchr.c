/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:19:08 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/11 02:18:30 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	char	*str;
	int		i;
	int		aux_value;

	i = 0;
	aux_value = value;
	str = (char *)ptr;
	if (value > 255)
		aux_value -= 256;
	while (num > 0)
	{
		if (str[i] == aux_value)
			return (str + i);
		num--;
		i++;
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