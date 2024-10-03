/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:48:07 by pamarti2          #+#    #+#             */
/*   Updated: 2024/03/22 19:48:07 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*int main(void)
{
    char c;
    char d;
    
    c = 'd';
    printf("%d\n", isdigit(c)); // el resultado es el doble de isalpha
    printf("%d", ft_isdigit(c));
    return (0);
}*/
/*#include <stdio.h>
#include <ctype.h>*/