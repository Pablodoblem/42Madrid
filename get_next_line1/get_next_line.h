/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:53:24 by pamarti2          #+#    #+#             */
/*   Updated: 2024/08/22 17:28:55 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>

typedef struct t_node
{
	char			*string_piece;
	struct t_node	*next;
}	t_node;

int		nlornll(char *buffer, int use);
t_node	*create_new_nodes(char *buffer, int n_chars_buf, int n, int c);
char	*get_next_line(int fd);
void	ft_strncpy(char *dest, const char *src, int size);
char	*join_strings(t_node *current);
void	free_all_nodes(t_node *head);
char	*handle_line(char **line);
char	*handle_buffer(char *buffer, t_node *head, char **line);
char	*handle_zero_read(char **line);
void	manage_nodes(t_node **head, t_node **current, t_node *new_node);

#endif