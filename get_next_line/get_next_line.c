/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:32:12 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/01 01:38:34 by pamarti2         ###   ########.fr       */
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

int	main(void)
{
	int		fd;
	char	buf[2000];
	int		chars_read;

	fd = open("text.txt", O_RDONLY);
	while ((chars_read = read(fd, buf, 35)))
	{
		buf[chars_read] = '\0';
		printf("buf -> %s\n", buf);
	}
}