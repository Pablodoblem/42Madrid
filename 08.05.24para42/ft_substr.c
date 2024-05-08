/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:38:03 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/07 02:22:51 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substring;
	int		aux_len;
	char	*str;

	str = "";
	aux_len = len;
	substring = malloc((len + 1) * sizeof(char));
	if (start > len)
		return (str);
	if (substring == NULL)
	{
		return (NULL);
	}
	s += start;
	while (*s && len > 0)
	{
		*substring = *s;
		substring++;
		s++;
		len--;
	}
	*substring = '\0';
	substring -= aux_len;
	return (substring);
}

// int main(void)
// {
//     const char *str = "lorem ipsum dolor sit amet";
//     printf("%s\n", ft_substr(str, 400, 20));
//     return (0);
// }