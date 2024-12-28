/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:56:29 by pamarti2          #+#    #+#             */
/*   Updated: 2024/12/28 17:33:45 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	//char	*str_char;
	int		contador;

	//str_char = (char *)str;
	contador = 0;
	while (*str != '\0')
	{
		contador++;
		str++;
	}
	return (contador);
}
