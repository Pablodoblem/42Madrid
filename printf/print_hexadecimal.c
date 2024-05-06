/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:18:27 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/27 13:25:11 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

// Función para escribir un solo carácter en la salida estándar
void write_char(char c) {
    write(1, &c, 1);
}

// Función para escribir una cadena en la salida estándar
void write_string(const char *str) {
    while (*str != '\0') {
        write_char(*str);
        str++;
    }
}

// Función para imprimir un puntero void * en formato hexadecimal
void print_hexadecimal(void *ptr) {
    uintptr_t address = (uintptr_t)ptr;
    char buffer[20]; // Suficiente espacio para almacenar la representación hexadecimal
    int len = 0;

    // Convertir el puntero a una cadena hexadecimal manualmente
    buffer[len++] = '0';
    buffer[len++] = 'x';
    for (int i = 15; i >= 0; i--) {
        int digit = (address >> (i * 4)) & 0xF;
        buffer[len++] = digit < 10 ? '0' + digit : 'a' + digit - 10;
    }
    buffer[len] = '\0';

    // Escribir la cadena hexadecimal en la salida estándar
    write_string(buffer);
    write_char('\n');
}

// int main() {
//     int x = 10;
//     print_hexadecimal(&x);
//     return 0;
// }