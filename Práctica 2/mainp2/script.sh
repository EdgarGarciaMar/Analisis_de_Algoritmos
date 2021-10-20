gcc main.c tiempo.c -o sal #compilación
#./sal (tamaño n) (opc 1-5) < 10millones(des-ord).txt > salida.txt
# Búsqueda binaria, exponecial y Fibonacci se ocupa el archivo 10millonesord.txt númeors ordenados
# Búsqueda lineal, ABB se ocupa el archivo 10millonesdes.txt números desordenados
./sal 1000000 1 < 10millonesdes.txt > salida-linear1.txt 
./sal 2000000 1 < 10millonesdes.txt > salida-linear2.txt 
./sal 3000000 1 < 10millonesdes.txt > salida-linear3.txt 
./sal 4000000 1 < 10millonesdes.txt > salida-linear4.txt 
./sal 5000000 1 < 10millonesdes.txt > salida-linear5.txt 
./sal 6000000 1 < 10millonesdes.txt > salida-linear6.txt 
./sal 7000000 1 < 10millonesdes.txt > salida-linear7.txt 
./sal 8000000 1 < 10millonesdes.txt > salida-linear8.txt 
./sal 9000000 1 < 10millonesdes.txt > salida-linear9.txt 
./sal 10000000 1 < 10millonesdes.txt > salida-linear10.txt 

 
./sal 300000 2 < 10millonesdes.txt >> salida-Arbol1.txt 
./sal 400000 2 < 10millonesdes.txt >> salida-Arbol2.txt 
./sal 500000 2 < 10millonesdes.txt >> salida-Arbol3.txt 
./sal 600000 2 < 10millonesdes.txt >> salida-Arbol4.txt 
./sal 700000 2 < 10millonesdes.txt >> salida-Arbol5.txt 
./sal 800000 2 < 10millonesdes.txt >> salida-Arbol6.txt 
./sal 900000 2 < 10millonesdes.txt >> salida-Arbol7.txt 
./sal 950000 2 < 10millonesdes.txt >> salida-Arbol8.txt 
./sal 1000000 2 < 10millonesdes.txt > salida-Arbol9.txt 
./sal 2000000 2 < 10millonesdes.txt > salida-Arbol10.txt

./sal 1000000 3 < 10millonesord.txt > salida-binaria1.txt
./sal 2000000 3 < 10millonesord.txt > salida-binaria2.txt
./sal 3000000 3 < 10millonesord.txt > salida-binaria3.txt
./sal 4000000 3 < 10millonesord.txt > salida-binaria4.txt
./sal 5000000 3 < 10millonesord.txt > salida-binaria5.txt
./sal 6000000 3 < 10millonesord.txt > salida-binaria6.txt
./sal 7000000 3 < 10millonesord.txt > salida-binaria7.txt
./sal 8000000 3 < 10millonesord.txt > salida-binaria8.txt
./sal 9000000 3 < 10millonesord.txt > salida-binaria9.txt
./sal 10000000 3 < 10millonesord.txt > salida-binaria10.txt

./sal 1000000 4 < 10millonesord.txt > salida-exponecial1.txt
./sal 2000000 4 < 10millonesord.txt > salida-exponecial2.txt
./sal 3000000 4 < 10millonesord.txt > salida-exponecial3.txt
./sal 4000000 4 < 10millonesord.txt > salida-exponecial4.txt
./sal 5000000 4 < 10millonesord.txt > salida-exponecial5.txt
./sal 6000000 4 < 10millonesord.txt > salida-exponecial6.txt
./sal 7000000 4 < 10millonesord.txt > salida-exponecial7.txt
./sal 8000000 4 < 10millonesord.txt > salida-exponecial8.txt
./sal 9000000 4 < 10millonesord.txt > salida-exponecial9.txt
./sal 10000000 4 < 10millonesord.txt > salida-exponecial10.txt

./sal 1000000 5 < 10millonesord.txt > salida-fibo1.txt
./sal 2000000 5 < 10millonesord.txt > salida-fibo2.txt
./sal 3000000 5 < 10millonesord.txt > salida-fibo3.txt
./sal 4000000 5 < 10millonesord.txt > salida-fibo4.txt
./sal 5000000 5 < 10millonesord.txt > salida-fibo5.txt
./sal 6000000 5 < 10millonesord.txt > salida-fibo6.txt
./sal 7000000 5 < 10millonesord.txt > salida-fibo7.txt
./sal 8000000 5 < 10millonesord.txt > salida-fibo8.txt
./sal 9000000 5 < 10millonesord.txt > salida-fibo9.txt
./sal 10000000 5 < 10millonesord.txt > salida-fibo10.txt

