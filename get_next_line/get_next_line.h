/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 00:53:24 by pamarti2          #+#    #+#             */
/*   Updated: 2024/06/11 18:01:04 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <ctype.h>
# include <errno.h>
# include <float.h>
# include <math.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <wchar.h>
# include <fcntl.h>

typedef struct node
{
	char		*string_piece;
	struct node	*next;
} node;

int		check_nl_or_null(char *buffer);
node	*create_new_node(char *buffer, int n_chars_buf);
void 	free_all_nodes(node *head);
char	*get_next_line(int fd);


#endif