/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:12:06 by pamarti2          #+#    #+#             */
/*   Updated: 2024/05/01 01:27:23 by pamarti2         ###   ########.fr       */
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
	int	fd;

	fd = open("text.txt", O_RDWR | O_CREAT | O_APPEND);

	//printf("fd of file: %d\n", fd);
	dup2(fd, 1);
	//write(1, "Hola\n", 5);
	write(fd, "Hola", 4);
	return (0);
}