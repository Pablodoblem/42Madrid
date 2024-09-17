/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:52:40 by pamarti2          #+#    #+#             */
/*   Updated: 2024/09/17 19:00:28 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

void	ft_strncpy(char *dest, const char *src, int size)
{
	int	counter;

	counter = 0;
	while (counter < size && src[counter] != '\0')
	{
		dest[counter] = src[counter];
		counter++;
	}
	while (counter < size)
	{
		dest[counter++] = '\0';
	}
}

void	free_all_nodes(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->string_piece);
		free(temp);
	}
	free(head);
}

int	nlornll(char *buffer, int use)
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
				return (counter);
			counter++;
		}
	}
	return (counter);
}

t_node	*create_new_nodes(char *buffer, int n_chars_buf, int n, int c)
{
	char	*ptr;
	t_node	*new_node;

	new_node = NULL;
	ptr = buffer;
	if (n == 1)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (NULL);
		new_node->next = NULL;
		new_node->string_piece = malloc((n_chars_buf + 1) * sizeof(char));
		if (!new_node->string_piece)
			return (NULL);
		ft_strncpy(new_node->string_piece, buffer, n_chars_buf);
		new_node->string_piece[n_chars_buf] = '\0';
		return (new_node);
	}
	while (n_chars_buf > 0)
	{
		*ptr = c;
		ptr++;
		n_chars_buf--;
	}
	return (new_node);
}

char	*join_strings(t_node *head)
{
	char		*chain;
	size_t		total_size;
	char		*position;
	t_node		*origin_head;

	total_size = ((origin_head = head), 0);
	while (head)
	{
		total_size += nlornll(head->string_piece, 2);
		head = head->next;
	}
	total_size += 2;
	chain = (char *)malloc(total_size * sizeof(char));
	if (!chain)
		return (NULL);
	position = chain;
	while (origin_head)
	{
		ft_strncpy(position, origin_head->string_piece,
			nlornll(origin_head->string_piece, 2));
		position += nlornll(origin_head->string_piece, 2);
		origin_head = origin_head->next;
	}
	*position = '\0';
	return (chain);
}
