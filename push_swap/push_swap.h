/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:13:36 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/10 01:51:23 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "push_swap.h"
# include <stdint.h>
# include <limits.h>

int				ft_write(const char *str);
int				ft_strlen(const char *str);
int				ft_atoi(char *str);
int             ft_isdigitmod(char *arg);
void			*ft_floatcalloc(size_t n, size_t size_of_element);

#endif