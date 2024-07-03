/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:52:40 by pamarti2          #+#    #+#             */
/*   Updated: 2024/06/28 11:16:40 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

char    *where_is_the_nl(char *buffer)
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

int	totalsize(node *current)
{
	int	size;

	size = 0;
	while(current)
	{
		size += strlen(current->string_piece);
		current = current->next;
	}
	size++;
	return (size);
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
	char	*chain;
	int		total_size;
	char	*position;

	total_size = totalsize(current) + 1;
	chain = (char *)malloc(total_size * sizeof(char));
	if (!chain)
		return (NULL);
	position = chain;
	while (current)
	{
		strcpy(position, current->string_piece);
		position += strlen(current->string_piece);
		current = current->next;
	}
	*position = '\0';
	return (chain);
}