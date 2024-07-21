/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:52:40 by pamarti2          #+#    #+#             */
/*   Updated: 2024/07/20 17:17:36 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

void	ft_strncpy(char *dest, const char *src, int size)
{
	size_t	counter;

	counter = 0;
	if (size != 0)
	{
		while (*src != '\0' && size > 0)
		{
			*dest = *src;
			dest++;
			src++;
			size--;
			counter += 1;
		}
	}
}

void	free_all_nodes(node *head)
{
	node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->string_piece);
		free(temp);
	}
}

int	check_nl_or_null(char *buffer, int use)
{
	int	counter;

	counter = 0;
	if (use == 1)
	{
		while (buffer[counter])
		{
			if (buffer[counter] == '\n')
				return (counter + 1);
			counter++;
		}
	}
	else if (use == 2)
	{
		while (buffer[counter])
		{
			if (buffer[counter] == '\0')
				return (counter + 1);
			counter++;
		}
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

	total_size = ((origin_current = current), 0);
	while (current)
	{
		total_size += check_nl_or_null(current->string_piece, 2);
		current = current->next;
	}
	total_size += 2;
	//printf("Total_size: %d\n", total_size);
	chain = (char *)malloc(total_size * sizeof(char));
	if (!chain)
		return (NULL);
	position = chain;
	while (origin_current)
	{
		strncpy(position, origin_current->string_piece, check_nl_or_null(origin_current->string_piece, 2));
		position += check_nl_or_null(origin_current->string_piece, 2);
		origin_current = origin_current->next;
	}
	*position = '\0';
	//printf("Chain[strlen(chain)]: %s", chain[total_size - 2]);
	return (chain);
}

/*

1. Solucionar función where_is_ther_nl (eliminarla dfel mapa) DONE
2. Sustituir todos los strlen por la función check DONE
3. Incluir función strcpy a utils DONE
4. Hay mallocs sin proteger DONE
5. Checkear casos en los que haya salto en el último caracter que lee la
función read en relación con el BUFFER_SIZE DONE

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
