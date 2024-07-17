/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:52:40 by pamarti2          #+#    #+#             */
/*   Updated: 2024/07/17 20:55:55 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

char    *where_is_the_nl(char *buffer) //me la puedo cargar
{
    char *ptr;

    ptr = buffer;
    while (*ptr != '\n')
    {
        if (*ptr == '\0')
            return (0);
        ptr++;
    }
    return (ptr);
}



void	free_all_nodes(node *head)
{
	node	*temp;

	while (head) // limpiar
	{
		temp = head;
		head = head->next;
		free(temp->string_piece);
		free(temp);
	}
}

int	check_nl_or_null(char *buffer)
{
	int	counter;

	counter = 0;
	while (buffer[counter])
	{
		if (buffer[counter] == '\n' || buffer[counter] == '\0')
			return counter + 1; // +1 es el útlimo cambio 16/06/2024
		counter++;
	}
	return (counter);
}

node	*create_new_nodes(char *buffer, int n_chars_buf)
{
	node	*new_node;
	
	new_node = (node *)malloc(sizeof(node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->string_piece = malloc((n_chars_buf + 1) * sizeof(char));
	if (!new_node->string_piece)
	{
		free(new_node);
		return (NULL);
	}
	strncpy(new_node->string_piece, buffer, n_chars_buf);
	new_node->string_piece[n_chars_buf] = '\0';
	return (new_node);
}

char	*join_strings(node *current)
{
	char		*chain;
	size_t		total_size;
	char		*position;
	node		*origin_current;

	total_size = ((origin_current = current),0);
	//origin_current = current;
	while(current)
	{
		total_size += strlen(current->string_piece);
		current = current->next;
	}
	total_size += 2;
	chain = (char *)malloc(total_size * sizeof(char));
	if (!chain)
		return (NULL);
	position = chain;
	while (origin_current)
	{
		strcpy(position, origin_current->string_piece);
		position += strlen(origin_current->string_piece);
		origin_current = origin_current->next;
	}
	*position = '\0';
	return (chain);
}

/*

1. Solucionar función where_is_ther_nl (eliminarla dfel mapa)
2. Sustituir todos los strlen por la función check
3. Incluir función strcpy a utils
4. Hay mallocs sin proteger
5. Algo mas

//funcion1()
//funcion2()
//
//y = 30;
//z = 40;
//int x = ((z = 40),(y = 30), funcion1(1), funcion2(), 0)

	head = ((current = NULL), NULL);
	;
		if (memset(buffer, 0, BUFFER_SIZE + 1) || read(fd, buffer, BUFFER_SIZE) <= 0))



*/
