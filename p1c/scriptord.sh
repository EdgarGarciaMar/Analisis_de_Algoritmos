#!/bin/bash
gcc main.c tiempo_ord.c -o sal
./sal 10 3 < numeros10millones.txt > salida.txt
./sal 15 3 < numeros10millones.txt >> salida.txt
./sal 20 3 < numeros10millones.txt >> salida.txt
