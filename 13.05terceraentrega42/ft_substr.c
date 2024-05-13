/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:38:03 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/13 18:52:03 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*write_substring(const char *s, size_t len, char *substring)
{
	while (*s && len > 0)
	{
		*substring = *s;
		substring++;
		s++;
		len--;
	}
	return (substring);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*substring;
	char		*aux;
	long int	safe_start;
	int			s_len;

	safe_start = start;
	s_len = ft_strlen(s);
	if (safe_start >= (long int)s_len)
	{
		substring = malloc(1 * sizeof(char));
		if (substring == NULL)
			return (NULL);
		return (*substring = '\0', substring);
	}
	if (len > s_len - start)
		len = s_len - start;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	s += start;
	aux = substring;
	if (*s && len > 0)
		substring = write_substring(s, len, substring);
	*substring = '\0';
	return (aux);
}

// int main(void)
// {
//     const char *str = "lorem ipsum dolor sit amet";
//     printf("%s\n", ft_substr(str, 400, 20));
//     return (0);
// }

// static char	*copy_in_substr(const char *s, size_t len, char *substring)
// {
// 	while (*s && len > 0)
// 	{
// 		*substring = *s;
// 		substring++;
// 		s++;
// 		len--;
// 	}
// 	return (substring);
// }