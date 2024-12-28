/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:25:19 by pamarti2          #+#    #+#             */
/*   Updated: 2024/12/28 16:26:19 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	char	*s1_char;
	char	*s2_char;
	int		total_len;

	s1_char = (char *)s1;
	s2_char = (char *)s2;
	total_len = ft_strlen(s1_char) + ft_strlen(s2_char);
	new_string = malloc((total_len + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	while (*s1_char != '\0')
	{
		*new_string = *s1_char;
		new_string++;
		s1_char++;
	}
	while (*s2_char != '\0')
	{
		*new_string = *s2_char;
		new_string++;
		s2_char++;
	}
	*new_string = '\0';
	return (new_string -= total_len, new_string);
}