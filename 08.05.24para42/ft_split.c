/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:32:49 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/07 02:15:16 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_split_counter(char const *s, char c)
{
	int	token;
	int	i;

	i = 0;
	token = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			token += 1;
		i++;
	}
	return (token);
}

static int	counttillnextsplit(const char *s, char c)
{
	int	counter;

	counter = 0;
	if (*s != '\0' && *s != c)
	{
		while (*s != '\0' && *s != c)
		{
			counter++;
			s++;
		}
	}
	else if (*s == c)
	{
		while (*s == c)
		{
			s++;
			counter++;
		}
	}
	return (counter);
}

static void	*conditionals(const char *s, char c, char **array_strings, int j)
{
	int	movement;

	movement = 0;
	if (array_strings == NULL)
		return (NULL);
	if (*s != c)
	{
		array_strings[j] = ft_substr(s, 0, counttillnextsplit(s, c));
		if (array_strings[j] == NULL)
		{
			while (j--)
				free(array_strings[j]);
			free(array_strings);
			return (NULL);
		}
		j++;
	}
	else if (*s == c)
	{
		movement = counttillnextsplit(s, c);
		s += movement;
		array_strings[j] = ft_substr(s, 0, counttillnextsplit(s, c));
	}
	j++;
	return (array_strings);
}

static int	first_steps(char **array_strings, const char *s, char c, int j)
{
	if (*s != c && *s != '\0')
	{
		conditionals(s, c, array_strings, j);
		j++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		counter;
	int		split_counter;
	char	**array_strings;
	int		j;

	j = 0;
	counter = 0;
	split_counter = str_split_counter(s, c);
	array_strings = (char **)malloc((split_counter + 1) * sizeof(char *));
	if (*s != c)
		j = first_steps(array_strings, s, c, j);
	while (*s != '\0' && j < split_counter)
	{
		if (*s == c)
		{
			s += counttillnextsplit(s, c);
			conditionals(s, c, array_strings, j);
			j++;
		}
		counter++;
		s++;
	}
	array_strings[j] = NULL;
	return (array_strings);
}

// int main(void) {
//     const char *str = "lorem ipsum dolor sit amet, ";
//     char c = 'z';
//     char **result = ft_split(str, c);
//     if (result != NULL) {
//         // Iterar sobre el array de strings e imprimir cada elemento
//         for (int i = 0; result[i] != NULL; i++) {
//             printf("String %d-->%s\n", i, result[i]);
//             free(result[i]); // Liberar la memoria asignada para cada string
//         }
//         free(result); // Liberar la memoria asignada para el array de strings
//     }
//     return 0;
// }