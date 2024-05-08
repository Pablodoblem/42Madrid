/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:48:10 by pamarti2          #+#    #+#             */
/*   Updated: 2024/03/22 19:48:10 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
int main(void)
{
    int c;
    
    c = -1;
    printf("%d\n", isascii(c));
    printf("%d\n", ft_isascii(c));
    return (0);
}*/
/*
int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Uso: %s <valor_de_c>\n", argv[0]);
        return 1;
    }

    int c;
    if (sscanf(argv[1], "%d", &c) != 1) {
        printf("El argumento no es un entero válido.\n");
        return 1;
    }

    printf("Testing with c = %d\n", c);
    
    printf("isascii(): %d\n", isascii(c));
    
    // Utiliza tu función ft_isascii() para comparar resultados
    printf("ft_isascii(): %d\n", ft_isascii(c));
    
    return 0;
}*/