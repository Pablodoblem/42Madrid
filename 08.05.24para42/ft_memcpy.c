/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:47:52 by pamarti2          #+#    #+#             */
/*   Updated: 2024/03/22 19:47:52 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr_char_dest;
	char	*ptr_char_src;
	int		i;

	i = 0;
	ptr_char_dest = (char *)dest;
	ptr_char_src = (char *)src;
	while (n > 0)
	{
		ptr_char_dest[i] = ptr_char_src[i];
		i++;
		n--;
	}
	return (ptr_char_dest);
}

// int main() 
// {
//     char source[] = "\0";
//     char destination[] = "holaquetalestas";
//     char source2[] = "\0";
//     char destination2[] = "holaquetalestas";

//     // Copiamos los datos desde source a destination
//     memcpy(destination, source, 13); 
//     ft_memcpy(destination2, source2, 13);
//     printf("Source: %s\n", source);
//     printf("Destination: %s\n", destination);
//     printf("MySource: %s\n", source2);
//     printf("MyDestination: %s\n", destination2);

//     return 0;
// }

/*
void    *ft_memcpy(void *s1, const void *s2, size_t n)
{
    char        *dest;
    const char  *src;
    size_t      i;
    
    dest = s1;
    src = s2;
    i = 0;
    if (!s1 && !s2)
        return (NULL);
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
*/
