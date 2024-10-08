/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:29:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/10/08 16:27:44 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

//int	check_lowest()
int	check_arg_format(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		//printf("Argumento %d: %s\n", i, argv[i]);
		if (ft_isdigitmod(argv[i]) == 1)
			return (1);
		if (ft_strlen(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		printf("No arguments provided\n");
		return (1);
	}
	if (check_arg_format(argc, argv) == 1)
	{
		printf("Invalid argument format\n");
		return (1);
	}
	while(i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	// // Supongamos que has calculado la secuencia de operaciones y las tienes en un array
	// char *operations[] = {"pb", "pb", "sa", "pa", "pa", "sa"};
	// int num_operations = 6;

	// for(int i = 0; i < num_operations; i++) {
	// 	printf("%s\n", operations[i]);
	// }

	return 0;
}
