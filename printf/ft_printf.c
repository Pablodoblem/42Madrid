/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:19:14 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/28 01:25:14 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "printf.h"
#include <stdint.h>

int	typology_checker(char const *command)
{
	char	*data_type;
	int		contador;

	contador = 0;
	data_type = "cspdiuxX";
	if (command[0] == '%')
	{
		while (command[0] == '%' && *data_type != '\0')
		{
			if (command[1] == *data_type)
				return (contador);
			data_type++;
			contador++;
		}
	}
	else
		return (1);
	return (0);
}
int ft_printf(char const *typo, ...)
{
	int			resultado_typology_checker;
	const char	*str;
	const void	*ptr;
	char		c;
	va_list		args;

	resultado_typology_checker = typology_checker(typo);
	switch(resultado_typology_checker)
	{
        case 0:
            va_start(args, typo);
            c = va_arg(args, char);
            write(1, &c, 1);
            va_end(args);
            break;
        case 1:
            va_start(args, typo);
            str = va_arg(args, const char *);
            ft_write(str);
            va_end(args);
            break;
        case 2:
			va_start(args, typo);
            ptr = va_arg(args, const void *);
            ft_writehexaptr(ptr);
            va_end(args);
			
            // Código para el caso cuando typology_checker devuelve 2
            break;
        case 3:
            // Código para el caso cuando typology_checker devuelve 3
            break;
		case 4:
            // Código para el caso cuando typology_checker devuelve 3
            break;
    	case 5:
            // Código para el caso cuando typology_checker devuelve 3
            break;
	    case 6:
            // Código para el caso cuando typology_checker devuelve 3
            break;
	    case 7:
            // Código para el caso cuando typology_checker devuelve 3
            break;
	    case 8:
            // Código para el caso cuando typology_checker devuelve 3
            break;
        // Agregar más casos según sea necesario
        default:
            // Manejar el caso cuando typology_checker devuelve un valor inesperado
            break;
    }
    
    return (0);
}

int main(void)
{
    char			*str = "String tipo char";
    // int				arrnbr[] = {1, 2, 3, 4, 5};
	// int				nbr = 345;
	// unsigned int	un_nbr = 234;
	// float			dec_nbr = 2.2;
	const void			*void_ptr;

	void_ptr = str;

	ft_printf("%p\n", void_ptr);
	printf("%p\n", void_ptr);
	return (0);
}