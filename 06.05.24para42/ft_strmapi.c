/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 23:35:03 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/10 14:02:58 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlenguarro(const char *str)
{
	int	contador;

	contador = 0;
	while (*str != '\0')
	{
		str++;
		contador++;
	}
	return (contador);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc((ft_strlenguarro(s) + 1));
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*str = "LoReM iPsUm";
	
	printf("ESTA ES LA CADENA ORIGINAL:\n");
	printf("%s\n", str);
	printf("ESTA ES LA CADENA MODIFICADA:\n");
	printf("%s\n", ft_strmapi(str, to_upper));
	return (0);
}*/