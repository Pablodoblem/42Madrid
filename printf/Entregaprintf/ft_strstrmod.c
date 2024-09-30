/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:23:44 by pamarti2          #+#    #+#             */
/*   Updated: 2024/09/29 18:47:34 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int	cspdiuxx_checker(char haystack)
{
	char	*needle;

	needle = "cspdiuxX%";
	while (*needle != '\0')
	{
		if (haystack == *needle)
			return (1);
		needle++;
	}
	return (0);
}

int	ft_strstrmod(const char *haystack, const char *needle)
{
	int		i;

	i = 0;
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0] && cspdiuxx_checker(haystack[i + 1]) == 1)
			return (i);
		i++;
	}
	return (-1);
}
