#!/bin/bash
gcc main.c tiempo_ord.c -o sal
./sal 100 1 < numeros10millones.txt > salida100.txt
./sal 1000 1 < numeros10millones.txt >> salida1000.txt
./sal 5000 1 < numeros10millones.txt >> salida5000.txt
./sal 10000 1 < numeros10millones.txt >> salida10000.txt
./sal 50000 1 < numeros10millones.txt >> salida50000.txt
./sal 100000 1 < numeros10millones.txt >> salida100000.txt