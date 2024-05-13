/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 23:35:03 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/13 18:04:17 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char changer(unsigned int num, char c)
// {
// 	if(c == 'a')
// 		c += num;
// 	return (c);
// }

// int	main(void)
// {
// 	char	*cadena_original = "Hola Mundo!";
// 	char	*cadena_modificada;

// 	// Llamada a ft_strmapi para convertir cada letra de la cadena a mayúsculas
// 	cadena_modificada = ft_strmapi(cadena_original, &changer);

// 	// Imprimir la cadena original y la cadena modificada
// 	printf("Cadena original: %s\n", cadena_original);
// 	printf("Cadena modificada: %s\n", cadena_modificada);

// 	// Liberar la memoria asignada dinámicamente para la cadena modificada
// 	free(cadena_modificada);

// 	return (0);
// }