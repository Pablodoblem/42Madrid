/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:23:44 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/11 00:40:47 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ptr2coincidence(const char *haystack, const char *needle,
		size_t len, int counter3)
{
	int		counter;
	int		counter2;
	int		length;
	char	*aux;

	length = (int)len;
	counter2 = 0;
	counter = ft_strlen(needle);
	aux = (char *)haystack;
	while (*haystack == *needle)
	{
		if (counter3 == length)
			break ;
		counter2++;
		haystack++;
		counter3++;
		needle++;
		if (counter == counter2)
			return (aux);
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		counter;
	int		counter2;
	size_t	counter3;
	char	*aux;

	counter = ft_strlen(needle);
	counter2 = 0;
	counter3 = 0;
	if (*needle == '\0')
	{
		aux = (char *)haystack;
		return (aux);
	}
	while (*haystack != '\0' && len > 0)
	{
		if (*haystack == *needle)
			if (ptr2coincidence(haystack, needle, len, counter3) != NULL)
				return (ptr2coincidence(haystack, needle, len, counter3));
		if (counter3 >= len && counter != counter2)
			break ;
		counter2 = 0;
		counter3++;
		haystack++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str1[] = "lorem ipsum dolor sit amet";
// 	char	str2[] = "ipsumm";

// 	printf("%s\n", ft_strnstr(str1, str2, 29));
// 	return (0);
// }
