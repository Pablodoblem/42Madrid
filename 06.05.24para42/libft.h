/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:44:52 by pamarti2          #+#    #+#             */
/*   Updated: 2024/04/24 21:39:10 by pamarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>

char	*ft_strrchr(const char *string, int c);
void	*ft_strdup(const char *str);
char	*ft_strchr(const char *string, int c);
void	*ft_memset(void *s, char c, int n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	*ft_calloc(size_t n, size_t tamanyo);
void	ft_bzero(char *str, int n);
int		ft_toupper(int n);
int		ft_tolower(int n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	*ft_memchr(const void *ptr, int value, size_t num);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strncmp(const void *ptr1, const void *ptr2, size_t num);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif