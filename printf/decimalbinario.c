/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimalbinario.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:56:52 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/28 00:36:54 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "printf.h"

int	contar_cifras_long(unsigned long n)
{
	int	contador;
	int	num;

	contador = 0;
	num = n;
	while (num != 0)
	{
		contador++;
		num /= 10;
	}
	return (contador);
}

char *reverse_string(char *str) 
{
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    int i = 0;
    int j = length - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return (str);
}

char *int_to_string(unsigned long num)
{
    int i = 0;
    char *str;

    str = malloc((contar_cifras_long(num) + 2) * sizeof(char));
    if (num == 0) {
        str[i++] = '0';
    }
    while (num > 0) {
        str[i++] = num % 10 + '0';
        num /= 10;
    }
    str[i] = '\0';
    str = reverse_string(str);
    return (str);
}


void binario_a_decimal(int *binario, int longitud) 
{
    unsigned long   resultado = 0;
    unsigned long   potencia = 1;

    for (int i = longitud - 1; i >= 0; i--) {
        if (binario[i] == 1) {
            resultado += potencia;
        }
        potencia *= 2;
    }
    ft_write(int_to_string(resultado));
}

int *inversion(int *binary)
{
    int i;
    int *bininv;

    bininv = malloc(32 * sizeof(int));  
    i = 0;
    while (i <= 31)
    {
        if (*binary == 0)
            bininv[i] = 1;
        else if (*binary == 1)
            bininv[i] = 0;
        i++;
        if (i == 31 && *binary == 0)
        {
          bininv[i] = 1;
          break;
        }
        else if (i == 31 && *binary == 1)
        {
          bininv[i] = 0;
          break;
        }
        binary++;
    }
    return (bininv);
}

void *decimal_a_binario(int numero)
{
    int residuo;
    int *binario;
    int i = 0;
    int *binario_colocado;
    int j;
    int *bininv;

    j = 31;
    if (numero < 0)
    {
        bininv = malloc(32 * sizeof(int));
        binario = calloc(32, sizeof(int));
        binario_colocado = calloc(32, sizeof(int));
        numero *= -1;
        while (numero > 0)
        {
            residuo = numero % 2;
            numero = numero / 2;
            binario[i] = residuo;
            i++;
        }
        j -= i;
        while (i >= 0 && j <= 31)
        {
            binario_colocado[j] = binario[i];
            j++;
            i--;
        }
        bininv = inversion(binario_colocado);
        binario_a_decimal(bininv, 32);
    }
    else
        ft_write(ft_itoa(numero));
    return (binario_colocado);  
}

// int main() {
//     int numero = 5;
//     decimal_a_binario(numero);
//     return 0;
// }