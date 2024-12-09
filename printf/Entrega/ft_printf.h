/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:44:52 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/04 19:23:54 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "ft_printf.h"
# include <stdint.h>
# include <limits.h>

int				ft_printf(char const *typo, ...);
int				ft_write(const char *str);
int				ft_strlen(const char *str);
char			*ft_itoa(int n);
char			*ft_itoalarger(unsigned long n);
int				print_hexadecimal(void *ptr);
size_t			unsigned_num(unsigned int num);
int				hexa(int num, int flag);
unsigned long	count_digitslong(unsigned long n);
int				print_integer(int num);
char			*ft_toupper(char *str);
unsigned long	bnry_to_dec(int *binary, int length);
int				*inversion(int *binary);
void			*ft_calloc(size_t n, size_t size_of_element);
#endif