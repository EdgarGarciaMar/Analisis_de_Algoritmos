gcc hilo.c tiempo.c -o sal -lpthread #compilación
gcc threadBin.c tiempo.c -o salt -lpthread 
gcc exponencialhilo.c tiempo.c -o salex -lpthread -lm
gcc avlH.c tiempo.c -o sala -lpthread
gcc Fibonaccihilos.c tiempo.c -o salfi -lpthread

#Búsqueda binaria, exponecial y Fibonacci se ocupa el archivo 10millonesord.txt númeors ordenados
#Búsqueda lineal, ABB se ocupa el archivo 10millonesdes.txt números desordenados
#./sal (número de hilos) (tamaño -n-) < 10millonesdes.txt > salida.txt
./sal 5 1000000 < 10millonesdes.txt > salida-lineal1.txt 
./sal 5 2000000 < 10millonesdes.txt > salida-lineal2.txt 
./sal 5 3000000 < 10millonesdes.txt > salida-lineal3.txt 
./sal 5 4000000 < 10millonesdes.txt > salida-lineal4.txt 
./sal 5 5000000 < 10millonesdes.txt > salida-lineal5.txt 
./sal 5 6000000 < 10millonesdes.txt > salida-lineal6.txt 
./sal 5 7000000 < 10millonesdes.txt > salida-lineal7.txt 
./sal 5 8000000 < 10millonesdes.txt > salida-lineal8.txt 
./sal 5 9000000 < 10millonesdes.txt > salida-lineal9.txt 
./sal 5 10000000 < 10millonesdes.txt > salida-lineal10.txt

./salt 1000000 < 10millonesdes.txt > salida-Bin1.txt 
./salt 2000000 < 10millonesdes.txt > salida-Bin2.txt 
./salt 3000000 < 10millonesdes.txt > salida-Bin3.txt 
./salt 4000000 < 10millonesdes.txt > salida-Bin4.txt 
./salt 5000000 < 10millonesdes.txt > salida-Bin5.txt 
./salt 6000000 < 10millonesdes.txt > salida-Bin6.txt 
./salt 7000000 < 10millonesdes.txt > salida-Bin7.txt 
./salt 8000000 < 10millonesdes.txt > salida-Bin8.txt 
./salt 9000000 < 10millonesdes.txt > salida-Bin9.txt 
./salt 10000000 < 10millonesdes.txt > salida-Bin10.txt

./salex 1000000 < 10millonesdes.txt > salida-ex1.txt 
./salex 2000000 < 10millonesdes.txt > salida-ex2.txt 
./salex 3000000 < 10millonesdes.txt > salida-ex3.txt 
./salex 4000000 < 10millonesdes.txt > salida-ex4.txt 
./salex 5000000 < 10millonesdes.txt > salida-ex5.txt 
./salex 6000000 < 10millonesdes.txt > salida-ex6.txt 
./salex 7000000 < 10millonesdes.txt > salida-ex7.txt 
./salex 8000000 < 10millonesdes.txt > salida-ex8.txt 
./salex 9000000 < 10millonesdes.txt > salida-ex9.txt 
./salex 10000000 < 10millonesdes.txt > salida-ex10.txt

./sala 300000 < 10millonesdes.txt > salida-Arbol1.txt 
./sala 400000 < 10millonesdes.txt > salida-Arbol2.txt 
./sala 500000 < 10millonesdes.txt > salida-Arbol3.txt 
./sala 600000 < 10millonesdes.txt > salida-Arbol4.txt 
./sala 700000 < 10millonesdes.txt > salida-Arbol5.txt 
./sala 800000 < 10millonesdes.txt > salida-Arbol6.txt 
./sala 900000 < 10millonesdes.txt > salida-Arbol7.txt 
./sala 950000 < 10millonesdes.txt > salida-Arbol8.txt 
./sala 1000000 < 10millonesdes.txt > salida-Arbol9.txt 
./sala 2000000 < 10millonesdes.txt > salida-Arbol10.txt

./salfi 5 300000 < 10millonesdes.txt > salida-fi1.txt 
./salfi 5 400000 < 10millonesdes.txt > salida-fi2.txt 
./salfi 5 500000 < 10millonesdes.txt > salida-fi3.txt 
./salfi 5 600000 < 10millonesdes.txt > salida-fi4.txt 
./salfi 5 700000 < 10millonesdes.txt > salida-fi5.txt 
./salfi 5 800000 < 10millonesdes.txt > salida-fi6.txt 
./salfi 5 900000 < 10millonesdes.txt > salida-fi7.txt 
./salfi 5 950000 < 10millonesdes.txt > salida-fi8.txt 
./salfi 5 1000000 < 10millonesdes.txt > salida-fi9.txt 
./salfi 5 2000000 < 10millonesdes.txt > salida-fi10.txt


