# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamarti2 <pamarti2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 18:14:27 by pamarti2          #+#    #+#              #
#    Updated: 2024/12/28 18:05:41 by pamarti2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push.a

CC = gcc
CCFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

# -fsanitize=address

MY_SOURCES = main.c \
             ft_atoi.c \
             ft_strlen.c \
             ft_isdigitmod.c \
             ft_calloc.c \
			 movements_utils.c \
			 zero_mng_utils.c \
			 order_utils.c \
			 logistic_utils.c \
			 array_utils.c \
			 print_utils.c \
			 bubble_sort_utils.c \
			 ft_strjoin.c

OBJS = $(MY_SOURCES:.c=.o)

# Regla para compilar la librería
$(NAME): $(OBJS)
	@ar crs $(NAME) $(OBJS)

# Regla para compilar todos los archivos
all: $(NAME)

# Regla para compilar los archivos .c en .o
%.o: %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

# Limpiar los archivos objeto
clean:
	@$(RM) $(OBJS)

# Limpiar todo (archivos objeto y binarios)
fclean: clean
	@rm -f $(NAME)

# Limpiar todo y recompilar
re: fclean all

# Variable para definir cuántos números generar, por defecto 6
NUMS ?= 6

# Variable para definir el rango superior de los números aleatorios, por defecto 100
RANGE ?= 100

# Regla para ejecutar el programa con números aleatorios no repetidos
run: all
	@$(CC) $(CCFLAGS) -o push_exec $(OBJS)
	@./push_exec $(shell seq 1 $(RANGE) | shuf -n $(NUMS))

runcust: all
	@$(CC) $(CCFLAGS) -o push_exec $(OBJS)
	@./push_exec

.PHONY: all clean fclean re run

