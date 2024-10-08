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

#include "push_swap.h"
#include <stdio.h>

int	ft_isdigitmod(char *arg)
{
    while (*arg)
    {
        if(*arg < '0' || *arg > '9')
            return (1);
        arg++;
    }
    return (0);
}

// int main(void)
// {
//     printf("%d", ft_isdigitmod("3d"));
//     return (0);
// }