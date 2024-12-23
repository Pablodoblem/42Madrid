/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logistic_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:28:06 by pamarti2          #+#    #+#             */
/*   Updated: 2024/12/22 20:48:57 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	decrease_numbers(float **arr, int argc, int flag, int index)
{
	int i;
	int	cpy;

	if (index == -1)
		i = 0;
	i = 0;
	if (flag == 1)
	{
		while (i < argc - 1)
		{
			if ((*arr)[i] != 0.5 && (*arr)[i] != 0)
				(*arr)[i] -= 1;
			i++;
		}
	}
	else if (flag == 2) //revisar
	{
		while (i < ((argc - 1)- (argc / 2)))
		{
			if ((*arr)[i] > index)
			{
				(*arr)[i] -= 1;
			}
			i++;
		}
	}
	else if (flag == 3)
	{
		cpy = index;
		while (index < ((argc - 1)- (argc / 2)))
		{
			if ((*arr)[index] >= (*arr)[cpy] && (*arr)[index] != 0.5)
			{
				(*arr)[index] -= 1;
			}
			index++;
		}
	}
}

void	increase_numbers(float **arr, int argc, int flag, int index)
{
	int i;
	int	cpy;

	if (index == -1)
		i = 0;
	i = 0;
	if (flag == 1)
	{
		while (i < argc - 1)
		{
			if ((*arr)[i] != 0.5)
			{
				(*arr)[i] += 1;
			}
			i++;
		}
	}
	else if (flag == 2)
	{
		cpy = index;
		while (index < ((argc - 1)- (argc / 2)))
		{
			index++;
			if ((*arr)[index] > (*arr)[cpy])
			{
				(*arr)[index] += 1;
			}
		}
	}
	else if (flag == 3)
	{
		cpy = index;
		while (index < ((argc - 1)- (argc / 2)))
		{
			if ((*arr)[index] >= (*arr)[cpy])
			{
				(*arr)[index] += 1;
			}
			index++;
		}
	}
	else if (flag == 4)
	{
		while (index < ((argc - 1)- (argc / 2)))
		{
			if ((*arr)[index] != 0.5)
				(*arr)[index] += 1;
			index++;
		}
	}
}

int	check_destination(float num, float **sortedarr_a, float **originalarr, int argc, float **arr_b, float lowest_num, int flag, int main_flag)
{
	int	counter;
	//int	result;
	int	i;
	int	y;

	i = 0;
	y = 0;
	counter = 0;
	if (flag == 1)
	{
		while (i < argc - 1)
		{
			if ((*originalarr)[i] == num)
				break ;
			i++;
		}
		while (i < argc - 1)
		{
			if ((*originalarr)[i] == lowest_num || (*originalarr)[i] == lowest_num + 0.5)
			{
				//counter--;
				break ;
			}
			printf("Inside counter: %d\n", counter); 
			counter++;
			i++;
		}
		printf("Counter - 1 = %d\n", counter - 1);
		return (counter - 1);
	}
	// Encontrar el índice de `num` en `sortedarr_a`
	else if (flag == 2)
	{
		while (i < argc - 1)
		{
			if ((*sortedarr_a)[i] == num)
			{
				i--;
				break ;
			}
			i++;
		}
		printf("sortedarr_a[i]: %.1f\n", (*sortedarr_a)[i]);
		printf("Originalarr[y]: %.1f\n", (*originalarr)[y]);
		// Buscar en `originalarr` para decidir el destino
		while (y < argc - 1)
		{
			if (main_flag == 0 || main_flag == 1)
			{
				if ((*originalarr)[y] == (*sortedarr_a)[i] || ((*originalarr)[y] - 0.5) == (*sortedarr_a)[i])
				{
					if ((*originalarr)[y] != (*sortedarr_a)[i])
						return (counter + 1);
					else if (!(((*sortedarr_a)[y]) - (int)(*sortedarr_a)[y] >= 0.4999) && ((*sortedarr_a)[y] - (int)(*sortedarr_a)[y] <= 0.5001))
					{
						printf("---------- ITERACIÓN DE FUNCIÓN CHECK DESTINATION ------------:\n");
						return (check_destination((*sortedarr_a)[i], sortedarr_a, originalarr, argc, arr_b, lowest_num, 2, main_flag));
					}
					// // result = check_bhind_lowest_num(originalarr, argc, lowest_num, (*sortedarr_a)[i]);
					// // printf("---------- FUNCIÓN CHECK DESTINATION ------------:\n");
					// // printf("result: %d\n", result);
					// if (result == -1)
					// {
					// 	// if (!(((*sortedarr_a)[y]) - (int)(*sortedarr_a)[y] >= 0.4999) && ((*sortedarr_a)[y] - (int)(*sortedarr_a)[y] <= 0.5001))
					// 	// 	return (check_destination((*sortedarr_a)[i], sortedarr_a, originalarr, argc, arr_b, lowest_num, 2, main_flag));
					// 	else
					// 	{
					// 		printf("sortedarr[i]: %.1f\n", (*sortedarr_a)[i]);
					// 		printf("originalarr[i]: %.1f\n", (*originalarr)[i]);
					// 		return (counter + 1);
					// 	}
					// }
					// else if (result == 1)
					// {
					// 	if (((*originalarr)[y] == (*sortedarr_a)[i] + 0.5 || ((*originalarr)[y] - 0.5) == (*sortedarr_a)[i] + 0.5))
					// 		return (counter + 1);
					// 	return (check_destination((*sortedarr_a)[i], sortedarr_a, originalarr, argc, arr_b, lowest_num, 2, main_flag));
					// }
				}
			}
			counter++;
			y++;
		}

		// Buscar en `arr_b` si no se encuentra en `originalarr`
		y = 0;
		counter = 0;
		if ((*arr_b)[y] != 0.5)
		{
			while (y < argc - 1)
			{
				if ((*arr_b)[y] == (*sortedarr_a)[i])
					return (counter *= -1);
				counter++;
				y++;
			}
		}
	}	
	return (0);
}

void	block_ordered_num(float **originalarr, float **arr_b, float **sortedarr, int argc, float lowest_num)
{
	int		i;
	int		y;
	float	*aux;
	int		counter;
	int		x;
	//int		y_aux[] = {0, 0, 0, 0, 0, 0};
	int		*y_aux;
	int		z;
	int		f;
	int		e;
	//int		auxaux;


	
	e = 0;
	z = 0;
	counter = 0;
	i = 0;
	y = 1;
	f = y;
	x = 0;
	//y_aux = y;
	printf("Valor de argc: %d\n", argc);
	printf("Valor de z: %d\n", z);
	printf("Valor de i: %d\n", i);
	y_aux = make_aux_array(argc);
	//auxaux = *y_aux;
	//printf("Valor de auxaux: %d\n", auxaux);
    if (y_aux == NULL)
		exit (1); // NO SE RICK ------------------------------------------
	//y_aux = ft_floatcalloc((argc - 1), sizeof(float));
	while (i < argc - 1)
	{
		y_aux[i] = 0;
		i++;
	}
	i = 0;
	aux = ft_floatcalloc((argc - 1), sizeof(float));
	
	while (i < argc - 1) //función de copia
	{
		aux[i] = (*originalarr)[i];
		i++;
	}
	i = 0;
	while (i < argc - 1) // función de búsqueda de lowest number
	{
		if (aux[0] == lowest_num || aux[0] == lowest_num + 0.5)
			break ;
		rx_to_stack(&aux, arr_b, 'a', argc);
		printf("aux[0]: %.1f\n", aux[0]);
		i++;
	}
	e = i;
	//printf("Valor de e: %d\n", e);
	i = 0;
	//printf("Valor de aux[i]: %.1f\n", aux[i]);
	printf("aux[0]: %.1f\n", aux[0]);
	while (x < argc - 2) //revisar y registrar opción con mayor número de bloqueos
	{
		y = f;
		//printf("Valor de f: %d\n", f);
		while (i < argc - 1 && y < argc - 1)
		{
			//printf("Valor de sortedarr[y]: %.1f\n", (*sortedarr)[y]);
			//printf("Valor de aux[i]: %.1f\n", aux[i]);
			if (aux[i] == (*sortedarr)[y]) // antes estaba con (*originalarr)[] en vez de aux
			{
				printf("aux[i]: %.1f\n", aux[i]);
				printf("(*sortedarr)[y]): %.1f\n", (*sortedarr)[y]);
				y++;
				counter++;
			}
			i++;
		}
		i = 0;
		y_aux[z] = counter;
		f += 1;
		// printf("Valor de y_aux[z]: %d\n", y_aux[z]);
		// printf("Valor de y: %d\n", y);
		counter = 0;
		z++;
		x++;
	}
	i = 0;
	y = 0;
	x = 0;
	while (i < argc - 1)
	{
		//printf("holax\n");
		//printf("Valor de y_aux[i]: %d\n", y_aux[i]);
		if (y_aux[i] > x)
		{
			y = i;
			x = y_aux[i];
		}
		i++;
	}
    i = 0;
    y++;
	// printf("Valor de y: %d\n", y);
	// printf("Valor de aux[i] de nuevo: %.1f\n", aux[i]);
	// printf("Valor de (*sortedarr)[y]: %.1f\n", (*sortedarr)[y]);
	// printf("Valor de i: %d\n", i);
	while (i < argc - 1) //conociendo
	{
		if (aux[i] == (*sortedarr)[y])
		{
			x = i + e;
			if (x > argc - 2)
				x -= (argc - 1);
			//printf("(*originalarr)[x]: %.1f\n", (*originalarr)[x]);
			if ((*originalarr)[x] != (*sortedarr)[argc - 2])
			    (*originalarr)[x] += 0.5;
			y++;
		}
		i++;
	}
	i = 0;
	printf("Y_AUX:\n");
	while (i < argc - 1)
	{
		printf("%d\n", y_aux[i]);
		i++;
	}
	free (aux);
	free (y_aux);
}