#!/bin/bash

# Definir los colores
verde="\e[32m"
rojo="\e[31m"
reset="\e[0m"

# Clean
echo -e "${verde}Haciendo clear...${reset}"
clear

# Ejecutar make
echo -e "${verde}Ejecutando make...${reset}"
make

# Ejecutar make
echo -e "${verde}Comprobando relink...${reset}"
make

# Comprobar si make fue exitoso
if [ $? -ne 0 ]; then
    echo -e "${rojo}Error en el comando make.${reset}"
    exit 1
fi

# Ejecutar make clean
echo -e "${verde}Ejecutando make clean...${reset}"
make clean

# Compilar con gcc
echo -e "${verde}Compilando con gcc -Wall -Wextra -Werror...${reset}"
gcc -Wall -Wextra -Werror -g libftprintf.a -o a.out

# Comprobar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo -e "${verde}Compilación exitosa.${reset}"
    echo -e "${verde}Ejecutando a.out...${reset}"

# Ejecutar el archivo generado:
echo -e "${verde}Ejecución simple...${reset}"
./a.out

# Ejecutar el archivo generado con Valgrind
# echo -e "${verde}Ejecución de a.out con valgrind estricto...${reset}"
# valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./a.out
else
    echo -e "${rojo}Error en la compilación.${reset}"
fi
