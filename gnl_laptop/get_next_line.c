/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:55:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/09/17 18:58:34 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

char	*handle_line(char **line)
{
	char	*auxptr;
	char	*auxchain;
	t_node	*new_node;

	auxchain = malloc((nlornll(*line, 1) + 1) * sizeof(char));
	if (!auxchain)
		return (NULL);
	ft_strncpy(auxchain, *line, nlornll(*line, 1));
	auxchain[nlornll(*line, 1)] = '\0';
	if (nlornll(*line, 1) == nlornll(*line, 2))
	{
		free(*line);
		*line = NULL;
		return (auxchain);
	}
	auxptr = *line;
	auxptr += nlornll(*line, 1);
	new_node = create_new_nodes(auxptr, nlornll(auxptr, 2), 1, 0);
	if (!new_node)
		return (NULL);
	free(*line);
	*line = join_strings(new_node);
	free_all_nodes(new_node);
	return (auxchain);
}

char	*handle_buffer(char *buffer, t_node *head, char **line)
{
	char	*auxchain;
	char	*auxptr;
	t_node	*new_node;
	int		num;

	free (*line);
	num = ((auxptr = buffer + nlornll(buffer, 1)), 1);
	if (nlornll(buffer, 2) == 0)
		num = 0;
	if (nlornll(buffer, 1) != nlornll(buffer, 2)
		|| buffer[nlornll(buffer, 2) - num] == '\n')
	{
		new_node = create_new_nodes(auxptr, nlornll(auxptr, 2), 1, 0);
		if (!new_node)
			return (free(buffer), NULL);
		*line = join_strings(new_node);
		free_all_nodes(new_node);
	}
	auxchain = join_strings(head);
	free_all_nodes(head);
	return (free(buffer), auxchain);
}

void	manage_nodes(t_node **head, t_node **current, t_node *new_node)
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

void	manage_line(t_node **head, t_node **current, char **line)
{
	*head = create_new_nodes(*line, nlornll(*line, 2), 1, 0);
	*current = *head;
	free (*line);
	*line = NULL;
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	t_node		*new_node;
	t_node		*head;
	t_node		*current;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || fd < 0 || BUFFER_SIZE < 1)
		return (free(buffer), NULL);
	head = ((current = NULL), NULL);
	if (line && nlornll(line, 2) != nlornll(line, 1))
		return (free(buffer), handle_line(&line));
	if (line)
		manage_line(&head, &current, &line);
	while (1)
	{
		create_new_nodes(buffer, BUFFER_SIZE + 1, 2, 0);
		if (read(fd, buffer, BUFFER_SIZE) <= 0 && !head)
			return (free(buffer), NULL);
		new_node = create_new_nodes(buffer, nlornll(buffer, 1), 1, 0);
		manage_nodes(&head, &current, new_node);
		if (nlornll(buffer, 1) < BUFFER_SIZE || buffer[BUFFER_SIZE - 1] == '\n')
			return (handle_buffer(buffer, head, &line));
		current = new_node;
	}
}

#include <string.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("multiple_line_with_nl.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}
	char *line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("%s", line);
	close(fd);
	return 0;
}

//OBJETIVOS: 

// 1. Eliminar current de la función para poder proteger el 
//     malloc de buffer ABORTEDandFIXED X
// 2. Comprobar dentro del subjet si la función cumple la norma con la última 
//         línea cuando se trata de un salto de línea
// 3. Realizar comprobaciones de corrector 42Eval
// 4. Revisar cuestiones de norminette y formato

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
// 		// if (nlornll(line) != (size_t)check_nl_or_null(line))
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
// 		// 	ft_strncpy(auxchain, line, check_nl_or_null(line));
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