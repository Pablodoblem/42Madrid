/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:23:44 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/27 01:34:02 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "printf.h"

int	cspdiuxX_checker(char haystack)
{
	char	*needle;

	needle = "cspdiuxX";
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
		if (haystack[i] == needle[0] && cspdiuxX_checker(haystack[i + 1]) == 1)
			return (i);
		i++;
	}
	return (-1);
}

// int	main(void)
// {
// 	const char	str1[] = "Hola mi nombre es";
// 	const char	str2[] = "%";

// 	printf("%d\n", ft_strstrmod(str1, str2));
// 	return (0);
// }
