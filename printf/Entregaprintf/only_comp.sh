#!/bin/bash

# Definir los archivos a compilar
archivos="decimalbinario.c
 ft_%i.c 
 ft_itoa.c 
 ft_printf.c 
 ft_strlen.c 
 ft_strstrmod.c 
 ft_write.c 
 ft_writehexaptr.c 
 hexalower.c 
 hexaupper.c 
 print_hexadecimal.c"

# Compilar con gcc y las flags -Wall -Wextra -Werror
echo "Compilando los archivos con gcc -Wall -Wextra -Werror..."
gcc -Wall -Wextra -Werror $archivos -o b.out

# Comprobar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "Compilación exitosa."
    echo "El archivo ejecutable se llama 'b.out'."
else
    echo "Error en la compilación."
fi
