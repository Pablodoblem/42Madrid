/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:53:30 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/06 00:39:57 by pamarti2         ###   ########.fr       */
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

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("O: %d\n", printf(" %x ", 0));
	printf("C: %d\n", ft_printf(" %x ", 0));
	return (0);
}

// int main(void)
// {
// 	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. ...";
// 	printf("O: %d\n", printf(" %% %% %% "));
// 	printf("C: %d\n", ft_printf(" %% %% %% "));
// 	printf("O: %d\n", printf(" %d ", -1));
// 	printf("C: %d\n", ft_printf(" %d ", -1));
// 	printf("O: %d\n", printf("%c", '0' + 256));
// 	printf("C: %d\n", ft_printf("%c", '0' + 256));
// 	printf("O: %d\n", printf(" %s %s %s %s %s", " - ", "", "4", "", s2));
// 	printf("C: %d\n", ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2));
// 	printf("O: %d\n", printf(" %u ", -2));
// 	printf("C: %d\n", ft_printf(" %u ", -2));
// 	printf("O: %d\n", printf(" %X ", INT_MAX));
// 	printf("C: %d\n", ft_printf(" %X ", INT_MAX));
// 	printf("O: %d\n", printf(" %x ", INT_MAX));
// 	printf("C: %d\n", ft_printf(" %x ", INT_MAX));
// 	// printf("SE PUTO VIENE\n");
// 	// printf("O: %d\n", printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%...));
// 	// printf("AQUÍ VIENE LA CHUFA\n");
// 	// printf("C: %d\n", ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%...));
//     return (0);
// }
