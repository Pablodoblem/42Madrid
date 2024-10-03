/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:56:29 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/07 02:18:40 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	char	*str_char;
	int		counter;

	str_char = (char *)str;
	counter = 0;
	while (*str_char != '\0')
	{
		counter++;
		str_char++;
	}
	return (counter);
}

/*int	main(void)
{
	char	chain[50] = "Hola que tal estás.";

	printf("%d", ft_strlen(chain));
	return (0);
}*/
