/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:56:29 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/10 14:07:29 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	char	*str_char;
	int		contador;

	str_char = (char *)str;
	contador = 0;
	while (*str_char != '\0')
	{
		contador++;
		str_char++;
	}
	return (contador);
}

/*int	main(void)
{
	char	chain[50] = "Hola que tal estás.";

	printf("%d", ft_strlen(chain));
	return (0);
}*/
