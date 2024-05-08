/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:47:17 by pamarti2          #+#    #+#             */
/*   Updated: 2024/03/22 19:47:17 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, char c, int n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n > 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (s);
}

/*int main() // no hay control de rebasamiento
{
    int n;
    char c;
    
    n = 64;
    c = '$';
    

    char str[] = "Hola esto es una prueba de memset";
    ft_memset(str, c, n);
    printf("Después ft_memset: %s\n", str);

    char str2[] = "Hola esto es una prueba de memset";
    
    memset(str2, c, n);
    printf("Después memset: %s\n", str2);


    return 0;
}*/