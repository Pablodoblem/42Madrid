/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:55:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/07/04 01:44:01 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

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

char	*handle_line(char **line)
{
	char	*auxptr;
	char	*auxchain;
	node	*new_node;

	//printf("LINE: %s\n", *line);
	auxchain = malloc((check_nl_or_null(*line) + 1) * sizeof(char));
	if (!auxchain)
		return (NULL);
	strncpy(auxchain, *line, check_nl_or_null(*line));
	auxchain[strlen(*line)] = '\0';
	if (!where_is_the_nl(*line))
	{
		line = NULL;
		return (NULL);
	}
	auxptr = where_is_the_nl(*line); //capturar residuo del buffer
	auxptr++;
	new_node = create_new_nodes(auxptr, strlen(auxptr));
	if (!new_node)
	{
		free(auxchain);
		return (NULL);
	}
	//printf("NEW_LINE: %s\n", new_node->string_piece);
	*line = join_strings(new_node); //AQUI ESTA LA SOLUCIÓN
	//printf("LINE EN HANDLE LINE: %s\n", *line);
	return (auxchain);
}

char	*handle_buffer(char *buffer, node *head, char **line)
{
	char	*auxchain;
	char	*auxptr;
	node	*new_node;

	auxchain = join_strings(head);
	free_all_nodes(head);
	if (where_is_the_nl(buffer))
	{
		auxptr = where_is_the_nl(buffer); //capturar residuo del buffer
		auxptr++;
		new_node = create_new_nodes(auxptr, strlen(auxptr));
		*line = join_strings(new_node); //AQUI ESTA LA SOLUCIÓN
		//printf("LINE EN HANDLE BUFFER: %s\n", *line);
		if (!new_node)
			return (NULL);
		return (auxchain);
	}
	else
	{
		*line = NULL;
		return (auxchain);
	}
}

char	*handle_zero_read(char **line)
{
	char	*chain;

	if (*line)
	{
		chain = malloc((strlen(*line) + 2) * sizeof(char));
		chain[strlen(*line)] = '\n';
		chain[strlen(*line) + 1] = '\0';
		strcpy(chain, *line);
		*line = NULL;
		return (chain);
	}
	else
		return (NULL);
}

void manage_nodes(node **head, node **current, node *new_node)
{
	if (!new_node)
		return ;
	if (!*current)
		*current = new_node;
	if (!*head)
		*head = new_node;
	else
		(*current)->next = new_node;
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		buffer[BUFFER_SIZE + 1];
	node		*new_node;
	node		*head;
	node		*current;

	head = NULL;
	current = NULL;
	if (line)
	{
		if (strlen(line) != (long unsigned int)check_nl_or_null(line))
			return (handle_line(&line));
		head = create_new_nodes(line, check_nl_or_null(line));
		current = head;
	}
	while (1)
	{
		memset(buffer, 0, BUFFER_SIZE + 1);
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (handle_zero_read(&line));
		new_node = create_new_nodes(buffer, check_nl_or_null(buffer));
		manage_nodes(&head, &current, new_node);
		if (check_nl_or_null(buffer) < BUFFER_SIZE)
			return (handle_buffer(buffer, head, &line));
		else
			current = new_node;
	}
	return (NULL);
}

int	main(void)
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
		printf("\033[31mSTRING DESDE EL MAIN: \033[0m%s", line);
		free(line);
	}

	close(fd);
	return 0;
}

// char	*get_next_line(int fd)
// {
// 	static char	*line; //kay
// 	int			bytes_read; //kay
// 	char		buffer[BUFFER_SIZE + 1]; //kay
// 	//char		*auxptr;
// 	char		*chain;
// 	node		*new_node; //kay
// 	node		*head; //kay
// 	node		*current; //kay
// 	//char		*auxchain;
// 	char		*result;

// 	head = NULL;
// 	current = NULL;
// 	bytes_read = 0;
// 	if (line)
// 	{
// 		// if (strlen(line) != (long unsigned int)check_nl_or_null(line))
// 		// 	return (handle_line(line));
// 		// else
// 		// {
// 		// 	new_node = create_new_nodes(line, check_nl_or_null(line));
// 		// 	if (!new_node)
// 		// 		return (NULL);
// 		// 	line == NULL;
// 		// 	head = new_node;
// 		// 	current = new_node;
// 		// }
		
// 		result = handle_line(&line);
// 		if (result)
// 			return result;
// 		head = create_new_nodes(line, check_nl_or_null(line));
// 		current = head;
// 	}
		

// 		// if (strlen(line) != (long unsigned int)check_nl_or_null(line))
// 		// {
// 		// 	printf("LINE: %s\n", line);
// 		// 	auxchain = malloc((check_nl_or_null(line) + 1) * sizeof(char));
// 		// 	strncpy(auxchain, line, check_nl_or_null(line));
// 		// 	auxchain[strlen(line)] = '\0';
// 		// 	auxptr = where_is_the_nl(line); //capturar residuo del buffer
// 		// 	auxptr++;
// 		// 	new_node = create_new_nodes(auxptr, strlen(auxptr));
// 		// 	printf("NEW_NODE: %s\n", new_node->string_piece);
// 		// 	line = join_strings(new_node); //AQUI ESTA LA SOLUCIÓN
// 		// 	if (!new_node)
// 		// 		return (NULL);
// 		// 	return (auxchain);
// 		// }
// 		// else
// 		// {
// 		// 	new_node = create_new_nodes(line, check_nl_or_null(line));
// 		// 	if (!new_node)
// 		// 		return (NULL);
// 		// 	line == NULL;
// 		// 	head = new_node;
// 		// 	current = new_node;
// 		// }
// 	//}
// 	while (1)
// 	{
// 		memset(buffer, 0, BUFFER_SIZE + 1);
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read <= 0)
// 		{
// 			if (line)
// 			{
// 				chain = malloc((strlen(line) + 2) * sizeof(char));
// 				chain[strlen(line)] = '\n';
// 				chain[strlen(line) + 1] = '\0';
// 				strcpy(chain, line);
// 				line = NULL;
// 				return (chain);
// 			}
// 			else
// 				return (NULL);
// 		}
// 		new_node = create_new_nodes(buffer, check_nl_or_null(buffer));
// 		if (!new_node)
// 			return (NULL);
// 		if (!current)
// 			current = new_node;
// 		if (!head)
// 			head = new_node;
// 		else
// 			current->next = new_node;
// 		if (check_nl_or_null(buffer) < BUFFER_SIZE)
// 		{
// 			return (handle_buffer(buffer, head, &line));

// 			// chain = join_strings(head);
// 			// //printf("String entera que mandar por le return: %s\n", chain);
// 			// // while (head) // limpiar
// 			// // {
// 			// //     node *temp = head;
// 			// //     head = head->next;
// 			// //     free(temp->string_piece);
// 			// //     free(temp);
// 			// // }
// 			// free_all_nodes(head);
// 			// if (where_is_the_nl(buffer))
// 			// {
// 			// 	auxptr = where_is_the_nl(buffer); //capturar residuo del buffer
// 			// 	auxptr++;
// 			// 	new_node = create_new_nodes(auxptr, strlen(auxptr));
// 			// 	line = join_strings(new_node); //AQUI ESTA LA SOLUCIÓN
// 			// 	if (!new_node)
// 			// 		return (NULL);
// 			// 	return (chain);
// 			// }
// 			// else
// 			// {
// 			// 	line = NULL;
// 			// 	return (chain);
// 			// }
// 		}
// 		else
// 			current = new_node;
// 	}
// 	return (NULL);
// }