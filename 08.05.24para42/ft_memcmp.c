/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:35 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/07 02:07:40 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char	*ptr1_char;
	char	*ptr2_char;

	ptr1_char = (char *)ptr1;
	ptr2_char = (char *)ptr2;
	while (num > 0)
	{
		if (*ptr1_char != *ptr2_char)
		{
			if ((ft_isprint(*ptr1_char) == 0) && (ft_isprint(*ptr2_char) == 0))
				return (1);
			return (*ptr1_char - *ptr2_char);
		}
		ptr1_char++;
		ptr2_char++;
		num--;
	}
	return (0);
}
/*
int main(void) 
{
    char ptr1[] = "Hello";
    char ptr2[] = "Hallo";
    char ptr3[] = "Hello";
    char ptr4[] = "Hallo";
    
    printf("ESTA ES MI FUNCIÓN:\n");
    printf("%d\n", ft_memcmp(ptr1, ptr2, 5));
    printf("ESTA ES LA FUNCIÓN ORIGINAL:\n");
    printf("%d\n", memcmp(ptr3, ptr4, 5));

    return 0;
}
*/