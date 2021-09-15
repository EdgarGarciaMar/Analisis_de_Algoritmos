/*
Ejercicio 3: Simulación de Producto2Mayores
Producto de 2 mayores V. 1.0
Nombre: Edgar García Marciano, Grupo: 3CM12
compilación:
gcc Producto2.c -o p2
Ejecución:
./p2 valor de "n" = 2500 o 5000 < nombre del archivo.txt que se quiera medir
*/
#include <stdio.h>
#include <stdlib.h>

void Producto2Mayores(int A[], int n)
{
    int mayor1, mayor2, i, cont = 0;

    if (A[0] > A[1]) //A[1] > A[2]
    {
        cont++;        //verdad if1
        mayor1 = A[0]; //A[1]
        mayor2 = A[1]; //A[2]
        cont += 2;     //1+1 asignación
    }
    else
    {
        cont++;        //falso if1
        mayor1 = A[1]; //A[2]
        mayor2 = A[0]; //A[1]
        cont += 2;     //1+1 asignación
    }
    i = 2; //i=3
    while (i <= n)
    {
        if (A[i] > mayor1)
        {
            cont++; //verdad if2
            mayor2 = mayor1;
            mayor1 = A[i];
            cont += 2; //1+1 asignación
        }
        else if (A[i] > mayor2)
        {
            cont++; //falso if2 y verdad if3
            mayor2 = A[i];
            cont++; //1 asignación
        }
        cont += 2; //falso if3 y while
        i = i + 1;
    }
    printf("\nEl resutltado de %d x %d = %d\n", mayor1, mayor2, mayor1 * mayor2);
    printf("\ntiempo= %d\n", cont);
}
int main(int argc, char *argv[])
{
    //***********Variables***********************************************
    int n;
    //***Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)***
    if (argc != 2)
    {
        printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100 \n", argv[0]);
        exit(1);
    }
    //******Tomar el segundo argumento como tamaño del algoritmo********
    else
    {
        n = atoi(argv[1]);
    }
    //***************Lectura de arreglo por direccionamiento**************
    int A[n];
    for (int a = 0; a < n; a++)
    {
        scanf("%d", &A[a]);
        //printf("[%d]=%d\n", a, A[a]);
    }
    //***************Productos mayores**********************************
    Producto2Mayores(A, n);
    //********************Ciclo con el cual se generaron los 6 archivos****
    //for (int i = 0; i < n; i++)
    //{
    //printf("%d\n", rand() % 100000); Imprimir el caso medio con i = 0 i<n
    //printf("%d\n", i); Imprimir el peor caso con i=1 i<=n
    //printf("%d\n", n - i); Imprimir el mejor caso i=0 i<n
    //}

    return 0;
}