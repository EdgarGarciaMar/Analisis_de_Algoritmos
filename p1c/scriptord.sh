#!/bin/bash
gcc main.c tiempo_ord.c -o sal
./sal 21 1 < numeros10millones.txt > salida.txt
./sal 21 2 < numeros10millones.txt >> salida.txt
./sal 21 3 < numeros10millones.txt >> salida.txt
./sal 21 4 < numeros10millones.txt >> salida.txt
./sal 21 5 < numeros10millones.txt >> salida.txt
./sal 21 6 < numeros10millones.txt >> salida.txt
./sal 21 7 < numeros10millones.txt >> salida.txt
./sal 21 8 < numeros10millones.txt >> salida.txt
./sal 21 9 < numeros10millones.txt >> salida.txt