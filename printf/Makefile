# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 13:18:00 by pamarti2          #+#    #+#              #
#    Updated: 2024/10/04 18:31:35 by pamarti2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -rf


MY_SOURCES =ft_%i.c\
						ft_itoa.c\
						ft_itoalarger.c\
						ft_printf.c\
						ft_printint.c\
						ft_strlen.c\
						ft_unsigned_num.c\
						ft_write.c\
						ft_hexa.c\
						some_utils.c\
						ft_calloc.c\
						ft_print_hexadecimal.c

OBJS = $(MY_SOURCES:.c=.o)

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)

all: $(NAME)

%.o : %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<
clean:
	@$(RM) $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re