/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:53:30 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/11 12:52:06 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	check_format(const char *typo)
{
	char	*data_type;

	data_type = "cspdiuxX%";
	while (*data_type != '\0')
	{
		if (*typo == *data_type)
			return (*data_type);
		data_type++;
	}
	return (0);
}

int	launch_function(va_list args, int *counter, char flag)
{
	if (flag == 'c')
	{
		*counter += 1;
		write(1, ((char []){(char)va_arg(args, int)}), 1);
	}
	else if (flag == 's')
		*counter += ft_write(va_arg(args, const char *));
	else if (flag == 'p')
		*counter += print_hexadecimal(va_arg(args, void *));
	else if (flag == 'd')
		*counter += print_integer(va_arg(args, int));
	else if (flag == 'i')
		*counter += print_integer(va_arg(args, int));
	else if (flag == 'u')
		*counter += unsigned_num(va_arg(args, int));
	else if (flag == 'x')
		*counter += hexa(va_arg(args, int), 1);
	else if (flag == 'X')
		*counter += hexa(va_arg(args, int), 2);
	else if (flag == '%')
	{
		write(1, "%", 1);
		*counter += 1;
	}
	return (*counter);
}

int	check_percent(const char **typo, va_list args)
{
	char	flag;
	int		counter;

	counter = 0;
	while (**typo == '%')
	{
		(*typo)++;
		flag = check_format(*typo);
		if (flag != 0)
			launch_function(args, &counter, flag);
		(*typo)++;
	}
	return (counter);
}

int	ft_printf(char const *typo, ...)
{
	va_list	args;
	int		counter;

	va_start(args, typo);
	counter = 0;
	if (!typo)
		return (0);
	while (*typo != '\0')
	{
		counter += check_percent(&typo, args);
		if (!*typo)
			return (va_end(args), counter);
		else
			write (1, typo, 1);
		typo++;
		counter++;
	}
	va_end(args);
	return (counter);
}
