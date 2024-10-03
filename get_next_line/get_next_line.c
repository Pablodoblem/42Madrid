/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:55:54 by pamarti2          #+#    #+#             */
/*   Updated: 2024/09/19 15:37:51 by pamarti2         ###   ########.fr       */
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

char	*handle_buffer(char *buffer, t_node **head, char **line)
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
	auxchain = join_strings(*head);
	free_all_nodes(*head);
	return (free(buffer), auxchain);
}

void	manage_nodes(t_node **head, t_node **current, t_node *new_node)
{
	if (!*current)
		*current = new_node;
	if (!*head)
		*head = new_node;
	else
		(*current)->next = new_node;
}

char	*loop(t_node **head, t_node **current, char **line, int fd)
{
	t_node	*new_node;
	char	*buffer;

	while (1)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		create_new_nodes(buffer, BUFFER_SIZE + 1, 2, 0);
		if (read(fd, buffer, BUFFER_SIZE) <= 0 && !*head)
			return (free(buffer), NULL);
		new_node = create_new_nodes(buffer, nlornll(buffer, 1), 1, 0);
		manage_nodes(head, current, new_node);
		if (nlornll(buffer, 1) < BUFFER_SIZE || buffer[BUFFER_SIZE - 1] == '\n')
			return (handle_buffer(buffer, head, line));
		*current = new_node;
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*line;
	t_node		*head;
	t_node		*current;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	head = ((current = NULL), NULL);
	if (line && nlornll(line, 2) != nlornll(line, 1))
		return (handle_line(&line));
	if (line)
	{
		head = create_new_nodes(line, nlornll(line, 2), 1, 0);
		current = head;
		free (line);
		line = NULL;
	}
	return (loop(&head, &current, &line, fd));
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int fd = open("big_line_with_nl.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return 1;
// 	}
// 	char *line = NULL;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	free(line);
// 	printf("%s", line);
// 	close(fd);
// 	return 0;

// }