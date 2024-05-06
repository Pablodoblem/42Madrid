/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:10:15 by pamarti2          #+#    #+#             */
/*   Updated: 2024/03/25 00:57:06 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int	ft_toupper(int n)
{
	if (n >= 'a' && n <= 'z')
	{
		n = n - 32;
		return (n);
	}
	else
		return (n);
}
/*
int	main(void)
{
	int	n;

	n = 'f';
	printf("%c", ft_toupper(n));
	
	return (0);
}
*/
/*
int		main(void) // main del tester
{
	int		i;
	int		c;

	i = 'a';
	while (i <= 'z')
	{
		c = ft_toupper(i);
		write(1, &c, 1);
		i++;
	}
	i = 0;
		while (i <= 47)
	{
		c = toupper(i);
		write(1, &c, 1);
		i++;
	}
	return (0);
}*/