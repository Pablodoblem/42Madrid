/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:05:38 by pamarti2          #+#    #+#             */
/*   Updated: 2024/03/27 17:35:50 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlenguarro(char *str)
{
	int	contador;

	contador = 0;
	while (*str != '\0')
	{
		contador++;
		str++;
	}
	return (contador);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	char	*s1_char;
	char	*s2_char;
	int		total_len;

	s1_char = (char *)s1;
	s2_char = (char *)s2;
	total_len = ft_strlenguarro(s1_char) + ft_strlenguarro(s2_char);
	new_string = malloc((total_len + 1) * sizeof(char));
	while (*s1_char != '\0')
	{
		*new_string = *s1_char;
		new_string++;
		s1_char++;
	}
	while (*s2_char != '\0')
	{
		*new_string = *s2_char;
		new_string++;
		s2_char++;
	}
	*new_string = '\0';
	new_string -= total_len;
	return (new_string);
}
/*
int	main (void)
{
	char	*resultado;
	const char *s1 = "Hola que tal";
	const char *s2 = " estamos yo soy Pablo.";
	resultado = ft_strjoin(s1, s2);
	printf("%s\n\n", resultado);
	return (0);
}*/