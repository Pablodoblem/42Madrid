/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 01:45:33 by pamarti2          #+#    #+#             */
/*   Updated: 2024/09/29 17:41:41 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int	print_integer(int num)
{
	char	*str;
	int		counter;

	str = ft_itoa(num);
	ft_write(str);
	counter = ft_strlen(str);
	free(str);
	return (counter);
}
