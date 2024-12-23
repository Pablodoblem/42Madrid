/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_mng_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:22:35 by pamarti2          #+#    #+#             */
/*   Updated: 2024/12/22 20:44:54 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_zero(float **arr, int argc, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		while (i < argc - 1)
		{
			if ((*arr)[i] == 0.5)
				return (i);
			i++;
		}
	}
	else if (flag == 2)
	{
		while(i < argc - 1)
		{
			if ((*arr)[i] == 0)
				(*arr)[i] = 0.5;
			//printf("CERO ENCONTRADO -> %.1f\n", (*arr)[i]);
			i++;
		}
	}
	else if (flag == 3)
	{
		while(i < argc - 1)
		{
			if ((*arr)[i] == 0)
			{
				printf("CERO ENCONTRADO -> %.1f\n", (*arr)[i]);
				(*arr)[i] = 0.25;
			}
			printf("Check\n");
			//printf("CERO ENCONTRADO -> %.1f\n", (*arr)[i]);
			i++;
		}
	}
	return (-1);
}

void	manage_zeros(float **arr, int argc) // en caso de que haya ceros 
//intercalados estos son sustituidos con los valores más próximos
{
	int	x;
	int zero_pos;
	int	stop_flag;

	stop_flag = 0;
	while (find_zero(arr, argc, 1) != -1 && stop_flag == 0)
	{
		zero_pos = find_zero(arr, argc, 1);
		x = zero_pos;
		while ((*arr)[x] == 0.5 && x < argc - 2)
			x++;
		while (x > zero_pos)
		{
			(*arr)[x - 1] = (*arr)[x];
			x--;
			if (x == zero_pos)
				stop_flag = 1;
		}
	}
}

int	check_zero(float **arr_c, float **arr_b, int argc, int flag)
{
	int i;
	int	aux_i;
	int	ft;

	ft = 0;
	aux_i = -1;
	i = 0;

	if (flag == 1)
	{
		while (i < argc - 1 && (*arr_b)[0] != 0.5)
		{
			if ((*arr_c)[i] == 0)
			{
				if (ft == 0)
				{
					aux_i = i;
					printf("aux_i: %d\n", aux_i);
					ft = 1;
				}
				else if ((*arr_b)[aux_i] > (*arr_b)[i])
				{
					aux_i = i;
					printf("aux_i: %d\n", aux_i);
				}
				//counter ++;
			}
			i++;
		}
		return (aux_i);
	}
	else if (flag == 2)
	{
		while (i < argc - 1)
		{
			if ((*arr_c)[i] != 0.5)
				break ;
			i++;
		}
		return (0);
	}
	return (-1);
}