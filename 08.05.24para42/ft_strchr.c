/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:47:22 by pamarti2          #+#    #+#             */
/*   Updated: 2024/03/22 19:47:22 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	char	*non_cnst_string;

	non_cnst_string = (char *)string;
	if (c == '\0')
	{
		non_cnst_string += ft_strlen(non_cnst_string);
		return (non_cnst_string);
	}
	while (*non_cnst_string != '\0')
	{
		if (*non_cnst_string == c)
			return (non_cnst_string);
		non_cnst_string++;
	}
	return (0);
}

/*
int main()
{
    const char *string = "bonjour";
    int c = '\0';
    //char *resultado;

    //resultado = ft_strchr(string, c);
	printf("ESTA ES MI FUNCION:\n");
	printf("%s\n", ft_strchr(string, c));
	printf("\n");
	printf("ESTA ES LA FUNCION REAL:\n");
    printf("%s\n", strchr(string, c));
    return 0;
}*/