/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:20:29 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/07 02:16:26 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

	//for (unsigned int i = 0; s[i] != '\0'; i++) 
/*
int main()
{
    char cadena[] = "Hola mundo";

    // Llamada a ft_striteri con la función imprimir_con_indice
    ft_striteri(cadena, imprimir_con_indice);

    return 0;
}*/