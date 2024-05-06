/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebaprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:59:29 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/27 01:57:47 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "printf.h"
#include <stdint.h>

int	typology_checker(char const *typo, void *arg)
{
	char	*data_type;
	int		contador;
	// va_list	args;

	// va_start(args, typo);
	// c = va_arg(args, char);
	contador = 0;
	data_type = "cspdiuxX";
	if (typo[0] == '%')
	{
		while (typo[0] == '%' && *data_type != '\0')
		{
			if (typo[1] == *data_type)
			{
				execute_action(typo, contador);
				return (0);
			}
			data_type++;
			contador++;
		}
	}
	else
		return (1);
	return (0);
}
void	execute_action(const char *typo, int x, void *arg)
{
	//va_list	args;
	char *aux;

	//va_start(args, typo);
	// c = va_arg(args, char);
	if (x == 0)
		ft_write(typo);
	else if (x == 1)
	{}
	else if (x == 2)
	{}
	else if (x == 3)
	{}
	else if (x == 4)
	{
		int *ptr_int = (int *)arg;
		int valor_entero = *ptr_int;
		aux = ft_itoa(valor_entero);
		while (*aux != '\0')
		{
			write (1, aux, 1);
			aux++;
		}
	}
	else if (x == 5)
	{}
	else if (x == 6)
	{}
	else if (x == 7)
	{}
	else if (x == 8)
	{}

}

int ft_printf(char const *typo, ...)
{
	va_list	args;
	int	typo_len;
	int flag_position;
	int	i;

	i = 0;
	va_start(args, typo);
	typo_len = ft_strlen(typo);
	while (*typo != '\0')
	{
		flag_position = ft_strstrmod(typo, "%");
		while (i != flag_position && *typo != '\0')
		{
			write(1, typo, 1);
			i++;
			typo++;
		}
		typology_checker(typo, va_arg(args, void *));
		typo += 3;
	}
	return (0);
}

int	main(void)
{
	int	n;
	char *str = "Hola, tengo %d años";

	n = 54;
	ft_printf(str, n);
	return (0);
}

// int	read_and_send_flag_location(char *flag_ptr, int i)
// {
// 	int	len;

// 	len = ft_strlen(typo);
// 	if (flag_ptr[0] == '%')
// 		return (i);
// 	while (flag_ptr[i] != '\0' && i <= len)
// 	{
// 		if (flag_ptr[i] != "'" && flag_ptr[i + 1] != '%')
// 			return (i + 1);
// 		if (i == len)
// 			return (i + 1);
// 		i++;
// 	}
// 	return (-1);
// }
