/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:35:00 by pamarti2          #+#    #+#             */
/*   Updated: 2024/12/22 20:49:20 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	*make_aux_array(int argc)
{
	int	*aux;

	aux = malloc((argc - 1) * sizeof(int));
	if (aux == NULL)
        return(NULL);
	return (aux);	

}
