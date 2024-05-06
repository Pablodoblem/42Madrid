/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:44:52 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/28 18:42:55 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(char const *, ...);
void	ft_write(const char *str);
void	ft_writehexaptr(const void *ptr);
char	*ft_strchrmod(const char *string, int c);
int		ft_strlen(const char *str);
char	*ft_itoa(int n);
void    print_hexadecimal(void *ptr);
void    *decimal_a_binario(int numero);
void	*hexalower(int num);
void	*hexaupper(int num);
#endif