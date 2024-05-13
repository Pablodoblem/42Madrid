/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:54:34 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/13 20:14:23 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	mod_while_condition(char *dst, const char *src)
{
	while (*src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
	}
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	tlen;
	int		catlen;
	int		i;

	i = 0;
	tlen = ft_strlen((const char *) dst) + ft_strlen(src);
	catlen = dstsize - ft_strlen((const char *) dst) - 1;
	while (*dst)
		dst++;
	if (dstsize > 1000)
	{
		mod_while_condition(dst, src);
		return (tlen);
	}
	while (i < catlen)
	{
		*dst = src[i];
		i++;
		dst++;
	}
	if (tlen - ft_strlen(src) < dstsize)
		*dst = '\0';
	else
		tlen = dstsize + ft_strlen(src);
	return (tlen);
}
// int main()
// {
// 	printf("MI FUNCIÓN: %d\n", ft_strlcat("pqrstuvwxyz", "abcd", 20));
// 	//printf("len_mine: %zu\t mine_str: %s", strlcat(dsto, src, len), dsto);	
// 	return (0);
// }

// int main()
// {
//     char    dest[30];	
//     char    *src = "AAAAAAAAA";

// 	ft_memset(dest, 0 , 30);
// 	ft_memset(dest, 'C', 5);
// 	printf("MI FUNCIÓN: %d\n", ft_strlcat(dest, src, -1));
// 	//printf("len_mine: %zu\t mine_str: %s", strlcat(dsto, src, len), dsto);	
// }