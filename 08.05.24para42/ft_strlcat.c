/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:54:34 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/08 17:07:23 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	tlen;
	int		catlen;
	int		i;

	i = 0;
	tlen = ft_strlen((const char *) dst) + ft_strlen(src);
	catlen = dstsize - ft_strlen((const char *) dst) - 1;
	if ((int)dstsize < 0)
		return (tlen);
	while (*dst)
		dst++;
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
// int main(void)
// {
//     char dest[30]; 
// 	ft_memset(dest, 0, 30);
// 	//char		dsto[43] = "Hola";	
//     char *src = (char *)"AAAAAAAAA";
//     //size_t		len = -1;
// 	dest[0] = 'B';
// 	printf("MI FUNCION: %d", ft_strlcat(dest, src, -1));
// 	//printf("FUNCION ORIGINAL: %d", strlcat(dsto, src, len));
// 	return (0);	
// }