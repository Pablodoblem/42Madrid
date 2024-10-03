/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:48:26 by pamarti2          #+#    #+#             */
/*   Updated: 2024/03/22 19:48:26 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*str_char;

	str_char = (char *)str;
	while (n > 0)
	{
		*str_char = '\0';
		str_char++;
		n--;
	}
}

/*
int main() 
{
    char buffer[20] = "Ejemplo de bzero";
    
    
    ft_bzero(buffer, 5); // Existe desbordamiento del buffer
    
    printf("Después de bzero: %s\n", buffer);
    
    return 0;
}*/