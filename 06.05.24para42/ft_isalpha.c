/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:48:14 by pamarti2          #+#    #+#             */
/*   Updated: 2024/03/22 19:48:14 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		if (c >= 'a' && c <= 'z')
			return (1);
		else
			return (1);
	}
	else
	{
		return (0);
	}
}

/*
int main(void)
{
    int c;
    
    c = 'A';
    printf("%d\n", isalpha(c));
    printf("%d", ft_isalpha(c));
    return (0);
}*/