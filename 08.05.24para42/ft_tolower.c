/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:17:39 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/07 02:23:05 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int n)
{
	if (n >= 'A' && n <= 'Z')
	{
		n = n + 32;
		return (n);
	}
	else
		return (n);
}

/*
int	main(void)
{
	int	n;

	n = 'F';
	printf("%c", ft_tolower(n));
	return (0);
}*/