/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:13:36 by pamarti2          #+#    #+#             */
/*   Updated: 2024/12/23 00:04:37 by pamarti2         ###   ########.fr       */
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

void	        print_stacks(float *numarr_a, float *numarr_b, int argc);

//movement management//

void	        wx_to_stack(float **arr_a, float **arr_b, char stack);
void	        move_the_row(float **arr, int argc, int flag);
void	        px_to_stack(float **arr_a, float **arr_b, char stack, int argc);
void	        rx_to_stack(float **arr_a, float **arr_b, char stack, int argc);
void	        rrx_to_stack(float **arr_a, float **arr_b, char stack, int argc);

//zero management//

int         	find_zero(float **arr, int argc, int flag);
void	        manage_zeros(float **arr, int argc);
int	            check_zero(float **arr_c, float **arr_b, int argc, int flag);

//order utils//

int	            check_stack_order(float **arr_a, int argc, int flag);
int             good_order(float **arr, float **arr_b, int argc);
int	            order_stack_arr_c(float **arr_b, float **arr_c, int moves_to_deposit, int argc);

//logistic utils//

void	        decrease_numbers(float **arr, int argc, int flag, int index);
void	        increase_numbers(float **arr, int argc, int flag, int index);
int	            check_destination(float num, float **sortedarr_a, float **originalarr, int argc, float **arr_b, float lowest_num, int flag, int main_flag);
void	        block_ordered_num(float **originalarr, float **arr_b, float **sortedarr, int argc, float lowest_num);

//array utils//

int	*make_aux_array(int argc);

//bubble sort utils//

void	comparison_g1(float **arr_a, float **arr_b, int argc, int *ops);
void	comparison_g2(float **arr_a, float **arr_b, int argc, int *ops);

#endif