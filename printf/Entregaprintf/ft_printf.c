/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:53:30 by pamarti2          #+#    #+#             */
/*   Updated: 2024/09/29 20:50:59 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdint.h>
#include <limits.h>

char	check_format(const char *typo)
{
	char	*data_type;

	data_type = "cspdiuxX%";
	typo++;
	while (*data_type != '\0')
	{
		if (*typo == *data_type)
			return (*data_type);
		data_type++;
	}
	return (0);
}

size_t	launch_function(va_list args, size_t counter, char flag)
{
	if (flag == 'c')
	{
		counter++;
		write(1, ((char []){(char)va_arg(args, int)}), 1);
	}
	else if (flag == 's')
		counter += ft_write(va_arg(args, const char *));
	else if (flag == 'p')
		counter += print_hexadecimal(va_arg(args, void *));
	else if (flag == 'd')
		counter += print_integer(va_arg(args, int));
	else if (flag == 'i')
		counter += print_integer(va_arg(args, int));
	else if (flag == 'u')
		counter += dec_to_bnry(va_arg(args, int));
	else if (flag == 'x')
		counter += hexa(va_arg(args, int), 1);
	else if (flag == 'X')
		counter += hexa(va_arg(args, int), 2);
	else if (flag == '%')
	{
		write(1, "%", 1);
		counter++;
	}
	return (counter);
}

int	ft_printf(char const *typo, ...)
{
	va_list	args;
	size_t	counter;
	char	flag;

	va_start(args, typo);
	counter = 0;
	if (!typo)
		return (0);
	while (*typo != '\0')
	{
		if (*typo == '%')
		{
			flag = check_format(typo);
			if (flag != 0)
				counter += launch_function(args, counter, flag);
			typo += 2;
		}
		write (1, typo, 1);
		typo++;
		counter++;
	}
	va_end(args);
	return (counter);
}

#include <stdio.h>
#include <limits.h>

int main(void)
{
    // // char    c;
    // // // int		RO;
	// // // int		RC;
	// //char 	*ptr = "hola\0uetal";
	// //unsigned int n = 4294967295;

	// //  c = '0';
    // printf("O: %d\n", printf("O: %u\n", -233));
	// //printf("\n==\n");
	// //ft_printf("%c\n", 40, 1);
    // ft_printf("C: %d\n", printf("C: %u\n", -233));
	printf("O: %d\n", printf(" %u \n", 0));
	printf("C: %d\n", ft_printf(" %u \n", 0));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", -1));
	printf("C: %d\n", ft_printf(" %u \n", -1));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", 1));
	printf("C: %d\n", ft_printf(" %u \n", 1));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", 9));
	printf("C: %d\n", ft_printf(" %u \n", 9));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", 10));
	printf("C: %d\n", ft_printf(" %u \n", 10));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", 11));
	printf("C: %d\n", ft_printf(" %u \n", 11));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", 15));
	printf("C: %d\n", ft_printf(" %u \n", 15));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", 16));
	printf("C: %d\n", ft_printf(" %u \n", 16));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", 17));
	printf("C: %d\n", ft_printf(" %u \n", 17));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", 99));
	printf("C: %d\n", ft_printf(" %u \n", 99));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", 100));
	printf("C: %d\n", ft_printf(" %u \n", 100));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", 101));
	printf("C: %d\n", ft_printf(" %u \n", 101));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", -9));
	printf("C: %d\n", ft_printf(" %u \n", -9));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", -10));
	printf("C: %d\n", ft_printf(" %u \n", -10));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", -99));
	printf("C: %d\n", ft_printf(" %u \n", -99));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", -100));
	printf("C: %d\n", ft_printf(" %u \n", -100));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", -101));
	printf("C: %d\n", ft_printf(" %u \n", -101));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", INT_MAX));
	printf("C: %d\n", ft_printf(" %u \n", INT_MAX));
	printf("----------------\n");
	printf("O: %d\n", printf(" %u \n", INT_MIN));
	printf("C: %d\n", ft_printf(" %u \n", INT_MIN));
	printf("----------------\n");
// 	printf("O: %d\n", printf(" %u \n", LONG_MAX));
// 	//printf("O: %d\n", ft_printf(" %u \n", LONG_MAX));
// 	printf("----------------");
// 	printf("O: %d\n", printf(" %u \n", LONG_MIN));
// 	//printf("O: %d\n", ft_printf(" %u \n", LONG_MIN));
// 	printf("----------------");
// 	printf("O: %d\n", printf(" %u \n", UINT_MIN));
// 	//printf("O: %d\n", ft_printf(" %u \n", UINT_MIN));
// 	printf("----------------");
// 	printf("O: %d\n", printf(" %u \n", ULONG_MIN));
// 	//printf("O: %d\n", ft_printf(" %u \n", ULONG_MIN));
// 	printf("----------------");
// 	printf("O: %d\n", printf(" %u \n", 9223372036854775807LL));
// 	//printf("O: %d\n", ft_printf(" %u \n", 9223372036854775807LL));
// printf("----------------");
// 	printf("O: %d\n", printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
// 	//printf("O: %d\n", ft_printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
    return (0);
}

// int main()
// {
//     int entero = 985632;
//     char caracter = 'B';
//     char *cadena = NULL;
//     char *cadena_larga = "Este es un string largo";
//     char *cadena_vacia = "";
//     void *puntero = &entero;
//     void *puntero_null = NULL;
//     int num_negativo = -42;
//     int int_max = 2147483647;
//     int int_min = -2147483648;
//     unsigned int uint_max = 4294967295;

//     int original_ret, mi_ret;
//     //PRUEBA DE CARACTERES
//     printf("%s\n", "Prueba de impresión de caracteres");
//     printf("Original printf:\n");
//     original_ret = printf("Caracter: %c\n", caracter);
//     printf("Return: %d\n", original_ret);
//     original_ret = printf("%c\n", caracter);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Caracter: %c\n", caracter);
//     printf("Return: %d\n", mi_ret);
//     mi_ret = ft_printf("%c\n", caracter);
//     printf("Return: %d\n\n", mi_ret);
    
//     //PRUEBA CON CADENAS
//     printf("%s\n", "Prueba de impresión de cadenas");
//     printf("Original printf:\n");
//     original_ret = printf("Cadena: %s\n", cadena);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Cadena: %s\n", cadena);
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA CON CADENAS LARGAS
//     printf("%s\n", "Prueba de impresión de cadenas largas");
//     printf("Original printf:\n");
//     original_ret = printf("Cadena larga: %s\n", cadena_larga);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Cadena larga: %s\n", cadena_larga);
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA DE CADENAS VACIAS
//     printf("%s\n", "Prueba de impresión de cadenas vacías");
//     printf("Original printf:\n");
//     original_ret = printf("Cadena vacía: %s\n", cadena_vacia);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Cadena vacía: %s\n", cadena_vacia);
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA DE PUNTEROS
//     printf("%s\n", "Prueba de impresión de punteros");
//     printf("Original printf:\n");
//     original_ret = printf("Puntero: %p\n", puntero);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Puntero: %p\n", puntero);
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA DE PUNTERO NULL
//     printf("%s\n", "Prueba de impresión de puntero NULL");
//     printf("Original printf:\n");
//     original_ret = printf("Puntero NULL: %p\n", puntero_null);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Puntero NULL: %p\n", puntero_null);
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA NUMEROS DECIMALES
//     printf("%s\n", "Prueba de impresión de números decimales (base 10)");
//     printf("Original printf:\n");
//     original_ret = printf("Entero: %d\n", entero);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Entero: %d\n", entero);
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA ENTEROS
//     printf("%s\n", "Prueba de impresión de enteros (base 10)");
//     printf("Original printf:\n");
//     original_ret = printf("Entero: %i\n", entero);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Entero: %i\n", entero);
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA DECIMALES LARGOS
//     printf("%s\n", "Prueba de impresión de números decimales negativos");
//     printf("Original printf:\n");
//     original_ret = printf("Número negativo: %d\n", num_negativo);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Número negativo: %d\n", num_negativo);
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA NUMEROS SIN SIGNO
//     printf("%s\n", "Prueba de impresión de números sin signo (base 10)");
//     printf("Original printf:\n");
//     original_ret = printf("Unsigned Entero: %u\n", uint_max);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Unsigned Entero: %u\n", uint_max);
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA INT MAX, INT MIN UINT MAX
//     printf("%s\n", "Prueba de impresión de enteros máximos y mínimos");
//     printf("Original printf:\n");
//     original_ret = printf("Entero máximo: %d\n", int_max);
//     printf("Return: %d\n", original_ret);
//     original_ret = printf("Entero mínimo: %d\n", int_min);
//     printf("Return: %d\n", original_ret);
//     original_ret = printf("Unsigned Entero máximo: %u\n", uint_max);
//     printf("Return: %d\n", original_ret);

//     // printf("Mi ft_printf:\n");
//     // mi_ret = ft_printf("Entero máximo: %d\n", int_max);
//     // printf("Return: %d\n", mi_ret);
//     // mi_ret = ft_printf("Entero mínimo: %d\n", int_min);
//     // printf("Return: %d\n", mi_ret);
//     // mi_ret = ft_printf("Unsigned Entero máximo: %u\n", uint_max);
//     // printf("Return: %d\n\n", mi_ret);

//     //PRUEBA HEXADECIMALES MINUSCULA
//     printf("%s\n", "Prueba de impresión de números hexadecimales en minúsculas");
//     printf("Original printf:\n");
//     original_ret = printf("Hexadecimal (minúsculas): %x\n", entero);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Hexadecimal (minúsculas): %x\n", entero);
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA HEXADECIMALES MAYUSCULA
//     printf("%s\n", "Prueba de impresión de números hexadecimales en mayúsculas");
//     printf("Original printf:\n");
//     original_ret = printf("Hexadecimal (mayúsculas): %X\n", entero);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Hexadecimal (mayúsculas): %X\n", entero);
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA HEXADECIMALES 0
//     printf("%s\n", "Prueba de impresión de números hexadecimales para 0");
//     printf("Original printf:\n");original_ret = printf("Hexadecimal (mayúsculas): %X\nHexadecimal (minusculas): %x\n", 0, 0);
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");mi_ret = ft_printf("Hexadecimal (mayúsculas): %X\nHexadecimal (minusculas): %x\n", 0, 0);
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA PORCENTAJE
//     printf("%s\n", "Prueba de impresión de porcentaje");
//     printf("Original printf:\n");
//     original_ret = printf("Porcentaje: %%\n");
//     printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Porcentaje: %%\n");
//     printf("Return: %d\n\n", mi_ret);

//     //PRUEBA MULTIPLES PARAMETROS
//     printf("%s\n", "Prueba de impresión de multiples parametros");
//     printf("Original printf:\n");
//     original_ret = printf("Hola mi nombre es %s, tengo %d años, estudio en %s y este es mi printf:\n", "Raul", 22, "42 Madrid");
// 	printf("Return: %d\n", original_ret);

//     printf("Mi ft_printf:\n");
//     mi_ret = ft_printf("Hola mi nombre es %s, tengo %d años, estudio en %s y este es mi printf:\n", "Raul", 22, "42 Madrid");
//     printf("Return: %d\n\n", mi_ret);

//     return 0;
// }
// int	format_error_check(char const *typo)
// {
// 	int	len;
// 	int counter;

// 	len = ft_strlen(typo);
// 	counter = 0;
// 	while (counter < len)
// 	{
// 		if (*typo == '%')
// 		{
// 			if (check_format(typo) == 0)
// 				return (0);
// 		}
// 		counter++;
// 	}
// 	return (0);
// }