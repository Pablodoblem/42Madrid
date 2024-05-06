/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:07:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/25 00:13:10 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	char	*non_cnst_string;
	int		i;

	i = 0;
	non_cnst_string = (char *)string;
	if (c == '\0')
	{
		non_cnst_string += ft_strlen(non_cnst_string);
		return (non_cnst_string);
	}
	while (non_cnst_string[i] != '\0')
	{
		if (non_cnst_string[i] == c && non_cnst_string[i - 1] == "'")
			return (non_cnst_string);
		i++;
	}
	return (0);
}