#!/bin/bash
gcc main.c tiempo_ord.c -o sal
./sal 20 1 < numeros10millones.txt > salida.txt
./sal 20 2 < numeros10millones.txt >> salida.txt
./sal 20 3 < numeros10millones.txt >> salida.txt
./sal 20 4 < numeros10millones.txt >> salida.txt
./sal 20 5 < numeros10millones.txt >> salida.txt