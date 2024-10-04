/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:06:56 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/04 00:40:33 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*guess_positive(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	if ((arr[i] - arr [j]) > 0)
	{
		rotate(arr, a, size);
	}

			

}

int	*rotate(int *arr, char stack, int size)
{
	int	*a;
	int	i;
	int rotate_index;

	i = 0;
	a = malloc(size * sizeof(int))
	if (!a)
		return (NULL);
	while (i < size)
	{
		rotate_index = i + 1;
		if (rotate_index == (size - 1))
			rotate_index = 0;
		a[i] = arr[rotate_index];
		i++;
	}
	return (a);
}

int	*push_swap(int *arr, int size)
{
	int	*a;
	int	i;

	i = 0;
	a = malloc(size * sizeof(int));
	if (!a)
		return (NULL);
	// while (i < size)
	// {
	// 	a[i] = arr[i];
	// 	i++;
	// }
	guess_horl()

	return (a);
}

int	main(void)
{
	int	arr[] = {8, 4, 2, 6, 3, 1};
	int size = sizeof(arr) / sizeof(arr[0]);
	push_swap(arr, size);
	return (0);
}


// int	main(int argc, char **argv)
// {
// 	if (1 == arcg || (2 == argc && !argv[1][0]))
// 		return (1);
	
// 	return (0);
// }