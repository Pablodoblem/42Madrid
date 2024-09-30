# Nombre de la librería
NAME = libftprintf.a

# Compilador
CC = cc

# Opciones de compilación
CFLAGS = -Wall -Wextra -Werror

# Directorio de archivos fuente
SRCDIR = .

# Obtener automáticamente todos los archivos .c en el directorio
SRCS = $(wildcard $(SRCDIR)/*.c)

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

# Phony targets (objetivos ficticios para evitar conflictos con archivos reales)
.PHONY: all clean fclean re
