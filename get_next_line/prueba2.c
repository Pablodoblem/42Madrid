/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:55:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/06/16 14:51:40 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

typedef struct nodes
{
	char		*string_piece;
	struct nodes	*next;
} nodes;

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

nodes	*create_new_nodes(char *buffer, int n_chars_buf)
{
	nodes	*new_node;
	
	new_node = (nodes *)malloc(sizeof(nodes));
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

char    *where_is_the_nl(char *buffer)
{
    char *ptr;

    ptr = buffer;
    while (*ptr != '\0' && *ptr != '\n')
        ptr++;
    return (ptr);
}

int	totalsize(nodes *current)
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

char	*join_strings(nodes *current)
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

char    *get_next_linee(int fd)
{
    static char  *line;
    int         bytes_read;
    char        buffer[BUFFER_SIZE + 1];
    char        *auxptr;
    char        *chain;
    nodes        *new_node;
    nodes        *head;
    nodes        *current;
    char        *ptr;
    char        *auxchain;

    head = NULL;
    current = NULL;
    //line = NULL;
    //line = 1;
    bytes_read = 0;
    if (line)
    {
        //printf("\nStrlen: %ld, Checknl: %d\n", strlen(line), check_nl_or_null(line));
        //printf("strchr a line: %s\n", strchr(line, 10));
        if (strlen(line) != check_nl_or_null(line))
            {  

                auxchain = malloc(check_nl_or_null(line + 1) * sizeof(char));
                strncpy(auxchain, line, check_nl_or_null(line));
                auxchain[check_nl_or_null(line)] = '\0';
                //printf("Check de line: %d\n Strlen de line: %ld\n", check_nl_or_null(line), strlen(line));
                auxptr = where_is_the_nl(line); //capturar residuo del buffer
                auxptr++;
                new_node = create_new_nodes(auxptr, check_nl_or_null(auxptr));
                line = join_strings(new_node); //AQUI ESTA LA SOLUCIÓN
                //printf("\033[32mString residual excepcion: \033[0m%s\n", line); //este new_node es para encabezar el siguiente
                //printf("Chain: %s\n", chain);
                if (!new_node)
                    return (NULL);
                return(auxchain);
            }
        else
        {
            new_node = create_new_nodes(line, check_nl_or_null(line));
            if(!new_node)
                return(NULL);
            head = new_node;
            current = new_node;
        }
    }
    while(1)
    {
        //printf("Valor de line: %d\n", line);
        //printf("%d\n", BUFFER_SIZE);
        memset(buffer, 0, BUFFER_SIZE + 1);
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        printf("\033[0mBuffer: %s\n", buffer);
        //strncpy(buffer, fd, BUFFER_SIZE);
        //fd += strlen(buffer);
        if (bytes_read <= 0)
        {
            // if (line)
            // {
            //     chain = join_strings(head);
            //     return (chain);
            // }
            // while (head) // limpiar
            // {
            //     nodes *temp = head;
            //     head = head->next;
            //     free(temp->string_piece);
            //     free(temp);
            // }
            // return (chain);
            // else
            printf("HOla\n");
            return (NULL);
        }
        // if(bytes_read <= 0)
        // {
        //     //printf("STRING: %s\n", new_node->string_piece);
        //     return (NULL);
        // }
        //printf("Valor de checknlornull: %d\n", check_nl_or_null(buffer));
        new_node = create_new_nodes(buffer, check_nl_or_null(buffer));
        if (!new_node)
            return (NULL);
        if (!current)
            current = new_node;
        if (!head)
            head = new_node;
        else
            current->next = new_node;
        //printf("String desde la funcion: %s\n", join_strings(head));
        if (check_nl_or_null(buffer) < BUFFER_SIZE)
        {
            chain = join_strings(head); 
            //printf("String entera que mandar por le return: %s\n", chain);
            while (head) // limpiar
            {
                nodes *temp = head;
                head = head->next;
                free(temp->string_piece);
                free(temp);
            }
            auxptr = where_is_the_nl(buffer); //capturar residuo del buffer
            auxptr++;
            new_node = create_new_nodes(auxptr, strlen(auxptr));
            line = join_strings(new_node); //AQUI ESTA LA SOLUCIÓN
            printf("\033[32mString residual: \033[0m%s\n", line); //este new_node es para encabezar el siguiente
            if (!new_node)
                return (NULL);
            //head = new_node;
            //current = new_node;
            return(chain);
            // if (line == x)
            // {
            //     line++;
            //     //printf("Valor de x: %d, valor de line: %d\n", x, line);
            //     while (head)
            //     {
            //         nodes *temp = head;
            //         head = head->next;
            //         free(temp->string_piece);
            //         free(temp);
            //     }
            //     //close(fd);
            //     return (chain);
            // }
        }
        else
            current = new_node;      
    }
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
    //char *str = "Buenas tardes,\nme dejo las explicaciones para luego\nque tal estamos \nadiosgracias";
    // line = get_next_linee(str);
    // printf("%s\n", line);
    // printf("%d\n", BUFFER_SIZE);
    char *line;
    while ((line = get_next_linee(fd)) != NULL)
    {
        printf("\033[31mSTRING DESDE EL MAIN: \033[0m%s", line);
        free(line);
    }

    close(fd);
    return 0;
}