/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:48:20 by pamarti2          #+#    #+#             */
/*   Updated: 2024/03/22 19:48:20 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t tamanyo)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(n * tamanyo);
	while (n > 0)
	{
		arr[i] = 0;
		n--;
		i++;
	}
	return (arr);
}

/*int main()
{
	ft_calloc(5, 4);
    return 0;
}*/