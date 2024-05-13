/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:47:36 by pamarti2          #+#    #+#             */
/*   Updated: 2024/03/22 19:47:36 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*last_step(char *non_cnst_string, char *last_letter, int c)
{
	while (*non_cnst_string != '\0')
	{
		if (*non_cnst_string == c)
			last_letter = non_cnst_string;
		non_cnst_string++;
	}
	return (last_letter);
}

char	*ft_strrchr(const char *string, int c)
{
	char	*non_cnst_string;
	char	*last_letter;

	non_cnst_string = (char *)string;
	if (c >= 0 && c <= 255)
	{
		if (*string == '\0' && c != '\0')
			return (NULL);
		if (c == '\0' || *string == '\0' || *non_cnst_string == '\0')
			return (non_cnst_string += ft_strlen(non_cnst_string),
				non_cnst_string);
		if (c > 255)
			return (non_cnst_string);
		last_letter = NULL;
		if (*non_cnst_string != '\0')
			last_letter = last_step(non_cnst_string, last_letter, c);
		return (last_letter);
	}
	else
	{
		if ((c - 256) <= 255)
			return (non_cnst_string);
	}
	return (NULL);
}

// int main()
// {
//     const char *string = "";
//     int c = '\0';
//     char *resultado;

//     resultado = ft_strrchr(string, c);
//     printf("%s\n", resultado);
//     return 0;
// }

/*	if (c == '\0')
		return (NULL);*/