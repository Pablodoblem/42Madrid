/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_gnl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:06:10 by pamarti2          #+#    #+#             */
/*   Updated: 2024/06/09 12:06:12 by pamarti2         ###   ########.fr       */
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

typedef struct node
{
	char		*string_piece;
	struct node	*next;
} node;

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
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->string_piece = malloc((n_chars_buf + 1) * sizeof(char));
	// if (new_node->string_piece == NULL)
	// {
	// 	free(new_node);
	// 	return (NULL);
	// }
	strncpy(new_node->string_piece, buffer, n_chars_buf);
	new_node->string_piece[n_chars_buf] = '\0';
	return (new_node);
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
		printf("Lineas de buffer: ");
		printf("%s\n", buffer);
		if (char_read == 0)
			break ;
		printf("Chars_read: %d\n", char_read);
		n_chars_buf = check_nl_and_null(buffer);
		printf("Valor n_chars_buf: %d\n", n_chars_buf);
		new_node = create_new_node(buffer, n_chars_buf);
		printf("String de new_node->string_piece: %s\n", new_node->string_piece);
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
					printf("String residual que encabezará nueva línea: %s\n", new_node->string_piece);  // print de string residual para head
				}
			}
			printf("\n-------------------\n");
			printf("LÍNEA %d --> ", x);
			current = head;
			while (current != NULL) //printear las cadenas desde head
			{
				printf("%s", current->string_piece);
				current = current->next;
			}
			printf("\n-------------------\n");
			current = head;
			while (current != NULL) //liberar memoria de nodos de linea printeada
			{
				node *next = current->next;
				free(current->string_piece);
				free(current);  //Momento en el que se sibera el espacio de memoria (leak)
				current = next;
			}
			//printf("ESTE ES EL VALOR DE 'NEW_NODE': %s\n", new_node->string_piece);
			printf("\n");
			head = new_node; //head apunta al "trozo" que resta del buffer donde hay salto de linea
			current = new_node;
			//i--;
			//break ;
			if (strchr(new_node->string_piece, 10) != NULL) //Aquí es donde tengo el leak. Trato de leer 8bytes en l región *00210 cuando esta ya ha sido liberada previamente
			{
				x++;
				printf("ESTA ES LA EXCEPCIÓN PARA CUANDO HAY SALTO DE LINEA\n AL FINAL DE LA STRING RESIDUAL:");
				printf("\n-------------------\n");
				printf("LÍNEA %d --> %s", x, new_node->string_piece);
				printf("-------------------\n");
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
	//close(fd);
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