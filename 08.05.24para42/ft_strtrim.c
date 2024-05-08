/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:45:55 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/07 02:22:31 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	flag_guessing(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
		if (s1[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*new;
	size_t	len;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (flag_guessing(set, s1[i]) && s1[i])
		i++;
	while (flag_guessing(set, s1[len - 1]) && (len - 1))
		len--;
	if (len < i)
		len = i;
	new = malloc(len - i + 1);
	if (!new)
		return (NULL);
	while (i < len)
		new[k++] = s1[i++];
	new[k] = '\0';
	return (new);
}

//  int    main(void)
//  {
//      const char    *s1 = "lorem sit amet";
//      const char    *set = "te";
//      printf("%s\n", ft_strtrim(s1, set));
//      return (0);
//  }
