#!/bin/bash

# Definir los archivos a compilar
archivos="ft_dec_to_bnry.c
 ft_%i.c 
 ft_itoa.c 
 ft_itoalarger.c
 ft_printf.c
 ft_printint.c 
 ft_strlen.c  
 ft_write.c 
 hexalower.c  
 print_hexadecimal.c"

clear
# Compilar con gcc y las flags -Wall -Wextra -Werror
echo "Compilando los archivos con gcc -Wall -Wextra -Werror..."
#gcc -Wall -Wextra -Werror $archivos -o b.out
gcc -g $archivos -o b.out

# Comprobar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "Compilación exitosa."
    echo "El archivo ejecutable se llama 'b.out'."
else
    echo "Error en la compilación."
fi
