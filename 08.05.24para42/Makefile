# Nombre de la librería
NAME = libft.a

# Compilador
CC = cc

# Opciones de compilación
CFLAGS = -Wall -Wextra -Werror

# Directorio de archivos fuente
SRCDIR = .

# Lista de archivos .c
SRCS = ft_itoa.c ft_split.c ft_strnstr.c ft_memchr.c ft_strchr.c ft_strrchr.c ft_atoi.c \
ft_memcmp.c ft_strdup.c ft_strtrim.c ft_bzero.c ft_memcpy.c ft_striteri.c ft_substr.c \
ft_calloc.c ft_memmove.c ft_strjoin.c ft_tolower.c ft_isalnum.c ft_memset.c ft_strlcat.c \
ft_toupper.c ft_isalpha.c ft_putchar_fd.c ft_strlcpy.c ft_isascii.c ft_putendl_fd.c \
ft_strlen.c ft_isdigit.c ft_putnbr_fd.c ft_strmapi.c ft_isprint.c ft_putstr_fd.c ft_strncmp.c   # Añade aquí todos los archivos .c necesarios

# Objetos generados a partir de los archivos fuente
OBJS = $(SRCS:.c=.o)

# Regla por defecto
all: $(NAME)

# Regla para construir la librería estática
$(NAME): $(OBJS)
	ar rcs $@ $^

# Regla para compilar los archivos fuente en objetos
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(OBJS)

# Regla para eliminar todos los archivos generados
fclean: clean
	rm -f $(NAME)

# Regla para reconstruir el proyecto desde cero
re: fclean all

# Objetivos phony (ficticios) para evitar conflictos con archivos reales
.PHONY: all clean fclean re
