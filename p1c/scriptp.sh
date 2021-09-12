#!/bin/bash
gcc main.c tiempo_ord.c -o sal
./sal 100 1 < numeros10millones.txt > salida100.txt
./sal 1000 1 < numeros10millones.txt >> salida1000.txt
./sal 5000 1 < numeros10millones.txt >> salida5000.txt
./sal 10000 1 < numeros10millones.txt >> salida10000.txt
./sal 50000 1 < numeros10millones.txt >> salida50000.txt
./sal 100000 1 < numeros10millones.txt >> salida100000.txt
./sal 200000 1 < numeros10millones.txt >> salida200000.txt
./sal 400000 1 < numeros10millones.txt >> salida400000.txt
./sal 600000 1 < numeros10millones.txt >> salida600000.txt
./sal 800000 1 < numeros10millones.txt >> salida800000.txt
./sal 1000000 1 < numeros10millones.txt >> salida1000000.txt
./sal 2000000 1 < numeros10millones.txt >> salida2000000.txt
./sal 3000000 1 < numeros10millones.txt >> salida3000000.txt
./sal 4000000 1 < numeros10millones.txt >> salida4000000.txt
./sal 5000000 1 < numeros10millones.txt >> salida5000000.txt
./sal 6000000 1 < numeros10millones.txt >> salida6000000.txt
./sal 7000000 1 < numeros10millones.txt >> salida7000000.txt
./sal 8000000 1 < numeros10millones.txt >> salida8000000.txt
./sal 9000000 1 < numeros10millones.txt >> salida9000000.txt
./sal 10000000 1 < numeros10millones.txt >> salida10000000.txt