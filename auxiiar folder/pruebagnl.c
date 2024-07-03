/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebagnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:06:43 by pamarti2          #+#    #+#             */
/*   Updated: 2024/06/11 18:22:43 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <math.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <fcntl.h>

// typedef struct node
// {
// 	char		*string_piece;
// 	struct node	*next;
// } node;

int	check_nl_or_null(char *buffer)
{
	int	counter;

	counter = 0;
	while (buffer[counter])
	{
		if (buffer[counter] == '\n' || buffer[counter] == '\0')
			return counter;
		counter++;
	}
	return (counter);
}

node	*create_new_node(char *buffer, int n_chars_buf)
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

void free_all_nodes(node *head)
{
    node *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp->string_piece);
        free(tmp);
    }
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

char	*get_next_line(int fd)
{
	char	buffer[11];
	node	*new_node;
	node	*head;
	node	*current;
	int		x;
	int		char_read;
	int		n_chars_buf;
	char	*aux_ptr;
	char	*chain;
	node	*aux_node;
	static int	y;
	
	y = 1;
	char_read = 0;
	n_chars_buf = 0;
	x = 0; // esto es solo para hacer el print (numero de linea)
	head = NULL;
	current = NULL;
	while (1)
	{
		memset(buffer, 0, 11);
		char_read = read(fd, buffer, 10);
		if (char_read <= 0)
			break ;
		n_chars_buf = check_nl_or_null(buffer);
		new_node = create_new_node(buffer, n_chars_buf);
		if (!new_node)
		{
			free_all_nodes(head);
			return (NULL);
		}
		if (head == NULL)
			head = new_node;
		else
			current->next = new_node;
		if (strlen(new_node->string_piece) < 10)
		{
			x++;
			printf("Valor de x: %d, Valor de y: %d\n", x, y);
			if (n_chars_buf < 10)
			{
				aux_ptr = strchr(buffer, 10);
				if (aux_ptr != NULL)
				{
					aux_ptr++;
					aux_node = create_new_node(aux_ptr, (10 - n_chars_buf)); //será asignado como head al final del if
					if(!aux_node)
					{
						free_all_nodes(head);
						return (NULL);
					}
					aux_node->next = aux_node;
					new_node = aux_node;
				}
			}
			// printf("LÍNEA %d --> ", x);
			current = head;
			if (y == x)
			{
				chain = join_strings(current);
				if (!chain)
				{
					free_all_nodes(head);
					return (NULL);
				}
				free_all_nodes(head);
				//free(new_node);
				y++;
				printf("Valor de y: %d\n", y);
				return (chain);
			}
			free_all_nodes(head);
			head = new_node; //head apunta al "trozo" que resta del buffer donde hay salto de linea
			current = new_node;
			if (char_read < 10)
				break ;
			if (strchr(new_node->string_piece, 10) != NULL)
			{
				x++;
				if (y == x)
				{
					current = new_node;
					chain = join_strings(current);
					if (!chain)
					{
						free_all_nodes(new_node);
						return (NULL);
					}
					free_all_nodes(new_node);
					y++;
					printf("Valor de y: %d\n", y);
					return (chain);
				}
				free_all_nodes(new_node);
				head = NULL;
				current = NULL;
			}
		}
		else
			current = new_node;
	}
	free_all_nodes(head);
	return (NULL);
}

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}