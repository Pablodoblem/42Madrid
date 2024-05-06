/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:53:30 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/28 19:05:51 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "printf.h"
#include <stdint.h>

char	check_format(const char *typo)
{
	char	*data_type;

	data_type = "cspdiuxX";
	typo++;
	while (*typo != '\0')
	{
		if (*typo == *data_type)
			return (*data_type);
		data_type++;
	}
	return (0);
}

int	ft_printf(char const *typo, ...)
{
	va_list	args;

	va_start(args, typo);
	while (*typo != '\0')
	{
		if (*typo == '%')
		{
			if (check_format(typo) == 'c')
				write(1, ((char[]){(char)va_arg(args, int)}), 1);
			else if (check_format(typo) == 's') // en caso de que el parámetro sea un int debería lanzar error
				ft_write(va_arg(args, const char *));
			else if (check_format(typo) == 'p')
				print_hexadecimal(va_arg(args, void *));
			else if (check_format(typo) == 'd')
				ft_write(ft_itoa(va_arg(args, int)));
			else if (check_format(typo) == 'i')
				ft_write(ft_itoa(va_arg(args, int)));
			else if (check_format(typo) == 'u')
				decimal_a_binario(va_arg(args, int));
			else if (check_format(typo) == 'x')
				hexalower(va_arg(args, int));
			else if (check_format(typo) == 'X')
				hexaupper(va_arg(args, int));
			typo += 2;
		}
		write (1, typo, 1);
		typo++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	int n = 34567532;
	//char c = 'C';
	//char	*str_needle = "cuarto";
	char *str = "Hola, yo vivo en el piso: %x\n";
	//printf("%%\n", n);
	ft_printf(str, n);
	return (0);
}