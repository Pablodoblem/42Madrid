/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:47:41 by pamarti2          #+#    #+#             */
/*   Updated: 2024/03/22 19:47:41 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_strdup(const char *str)
{
	char	*new_arr;
	int		i;
	int		num_elementos;
	size_t	data_type_bytes;

	num_elementos = 0;
	i = 0;
	data_type_bytes = sizeof(str[0]);
	while (str[num_elementos] != '\0')
		num_elementos++;
	new_arr = (char *)malloc(data_type_bytes * (num_elementos + 1));
	while (num_elementos > 0)
	{
		new_arr[i] = str[i];
		num_elementos--;
		i++;
	}
	new_arr[i] = '\0';
	return (new_arr);
}

/*int main()
{
    const char    *str = "Hola que tal estamos";
	printf("%s\n", (char *)ft_strdup(str));
    printf("%s\n", strdup(str));

    return 0;
}*/