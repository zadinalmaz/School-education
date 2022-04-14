#!/bin/bash
read -p "Напиши название файла, до .*, для того чтобы скомпилировать его " file
gcc -std=c11 -Wall -Wextra -Werror -o $file.o $file.c
./$file.o
