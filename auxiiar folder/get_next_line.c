/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 00:46:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/06/14 10:46:40 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	check_nl_and_null(char *buffer)
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
	
	char_read = 0;
	n_chars_buf = 0;
	fd = open("text.txt", O_RDONLY);
	x = 0; // esto es solo para hacer el print (numero de linea)
	head = NULL;
	current = NULL;
	if (fd == -1)
		return (NULL);
	while (1)
	{
		memset(buffer, 0, 11);
		char_read = read(fd, buffer, 10);
		//printf("Lineas de buffer: ");
		//printf("%s\n", buffer);
		// if (char_read == 0)
		// 	break ;
		//printf("Chars_read: %d\n", char_read);
		n_chars_buf = check_nl_and_null(buffer);
		//printf("Valor n_chars_buf: %d\n", n_chars_buf);
		new_node = create_new_node(buffer, n_chars_buf);
		//printf("String de new_node->string_piece: %s\n", new_node->string_piece);
		if (head == NULL)
			head = new_node;
		else
			current->next = new_node;
		//printf("Check de que no ha salido del while\n");
		if (strlen(new_node->string_piece) < 10)
		{
			x++;
			if (n_chars_buf < 10)
			{
				aux_ptr = strchr(buffer, 10);
				if (aux_ptr != NULL)
				{
					aux_ptr++;
					new_node = create_new_node(aux_ptr, (10 - n_chars_buf)); //será asignado como head al final del if
					//printf("String residual que encabezará nueva línea: %s\n", new_node->string_piece);  // print de string residual para head
				}
			}
			//printf("\n-------------------\n");
			printf("LÍNEA %d --> ", x);
			current = head;
			while (current != NULL) //printear las cadenas desde head
			{
				printf("%s", current->string_piece);
				current = current->next;
			}
			free_all_nodes(head);
			printf("\n");
			//printf("\n-------------------\n");
			current = head;
			// while (current != NULL) //liberar memoria de nodos de linea printeada
			// {
			// 	node *next = current->next;
			// 	free(current->string_piece);
			// 	free(current);
			// 	current = next;
			// }
			//printf("ESTE ES EL VALOR DE 'NEW_NODE': %s\n", new_node->string_piece);
			printf("\n");
			head = new_node; //head apunta al "trozo" que resta del buffer donde hay salto de linea
			current = new_node;
			//i--;
			//break ;
			if (char_read < 10) //Solución para que al final de la lectura no haya segfault.
				break ;
			if (strchr(new_node->string_piece, 10) != NULL)
			{
				x++;
				//printf("ESTA ES LA EXCEPCIÓN PARA CUANDO HAY SALTO DE LINEA\n AL FINAL DE LA STRING RESIDUAL:");
				//printf("\n-------------------\n");
				printf("LÍNEA %d --> %s", x, new_node->string_piece);
				printf("\n");
				//printf("\n-------------------\n");
				free(new_node->string_piece);
				free(new_node);
				head = NULL;
				current = NULL;
			}
		}
		else
			current = new_node;
	}
	//printf("%s\n", strcpy(new_node->string_piece, buffer));
	close(fd);
	return (0);
}

int	main(void)
{
	//char	*fd;

	//fd = "Hola a todos soy pablo y estoy aprendiendo a programar\n espero que os guste.\n buenos días gente\n valos al lío";
	int	fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}