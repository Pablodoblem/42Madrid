/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:59:39 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/13 01:19:49 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	s_size;

	s_size = ft_strlen(s);
	while (*s != '\0' && s_size > 0)
	{
		write (fd, s, 1);
		s++;
		s_size--;
	}
}

// int		main(int argc, const char *argv[])
// {
// 	int		arg;

// 	//alarm(TIMEOUT);
// 	if (argc == 1)
// 		return (0);
// 	else if ((arg = atoi(argv[1])) == 1)
// 		ft_putstr_fd("lorem ipsum dolor sit amet", 2);
// 	else if (arg == 2)
// 		ft_putstr_fd("  lorem\nipsum\rdolor\tsit amet  ", 1);
// 	else if (arg == 3)
// 		ft_putstr_fd("", 2);
// 	else if (arg == 4)
// 		ft_putstr_fd("lorem ipsum do\0lor sit amet", 1);
// 	return (0);
// }