/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:53:29 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/13 18:53:55 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long int n)
{
	int	counter;
	int	num;

	counter = 0;
	num = n;
	while (num != 0)
	{
		counter++;
		num /= 10;
	}
	if (counter == 0)
		counter = 1;
	return (counter);
}

static char	*count_n_createstring(long int n)
{
	int		counter;
	char	*str;

	counter = count(n);
	if (n < 0)
	{
		counter++;
		str = malloc((counter + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '-';
	}
	else
	{
		str = malloc((counter + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
	}
	str[counter] = '\0';
	return (str);
}

static char	*write_with_conditions(char *str, int i, int str_len,
	long int number)
{
	long int	z;
	long int	x;

	z = 10;
	x = 1;
	if (number == 0)
		return (str[0] = '0', str);
	while (str_len > 0 && i >= 0)
	{
		if (str_len == 1)
		{
			while (number >= 10)
				number /= 10;
			str[i] = number + 48;
			return (str);
		}
		str[i] = (((number % z) / x) + 48);
		z *= 10;
		x *= 10;
		str_len--;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			str_len;
	int			i;
	long int	long_n;

	long_n = n;
	str = count_n_createstring(long_n);
	if (str == NULL)
		return (NULL);
	str_len = count(long_n);
	i = str_len;
	if (long_n >= 0)
		i = str_len - 1;
	else
		long_n *= -1;
	str = write_with_conditions(str, i, str_len, long_n);
	return (str);
}

// int	main(void)
// {
// 	//int	n = 0;
// 	printf("%s\n", ft_itoa(0));
// 	return (0);
// } 