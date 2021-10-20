//*****************************************************************
//Datos del Código base
//M. EN C. EDGARDO ADRIÁN FRANCO MARTÍNEZ
//Curso: Análisis de algoritmos
//(C) Enero 2013
//ESCOM-IPN
//*****************************************************************
//Datos del Código Actual
/*
Versión del programa: 2.0

Nombre del programa: Algoritmos de búsqueda de datos en lenguaje c con hilos

Descripción:


Errores:


Equipo: Noobcoders
Fuentes Díaz Jesús Alejandro
García Ledezma Miguel Ángel
García Marciano Edgar
Guadarrama Hidalgo Jorge Luis
Práctica 2
Análisis temporal (algoritmos de búsqueda)
Análisis de algoritmos
Franco Martínez Edgardo Adrián
3CM12

compilación:
gcc exponencialhilo.c tiempo.c -o sal -lpthread
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include "tiempo.h"
#define min(X, Y) (((X) < (Y)) ? (X) : (Y)) //Definicion de min entre 2 numeros

struct bin_args //Argumentos de los hilos
{
    int *arr;
    int l;
    int r;
    int x;
};

void *binarySearch(void *arguments) // definicion de la busqueda binaria
{
    pthread_detach(pthread_self()); //Recepcion de argumentos
    struct bin_args *args = arguments;
    int *arr = args->arr;
    int l = args->l;
    int r = args->r;
    int x = args->x;
    double times = log(r + 1) / log(2);
    int mid, value = -1;

    for (int i = 0; i <= times; i++)
    {
        if (r >= l)
        {
            mid = l + (r - l) / 2;
            if (arr[mid] == x)
            {
                value = mid;
                break;
            }
            else if (arr[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    (value == -1) ? printf("Element is not present in array\n")
                  : printf("Element is present at index %d\n", value);
}

void *exponentialSearch(int arr[], int n, int x)//Recibe el arreglo, n y el valor del arreglo a buscar
{
    pthread_t threads[4];
    int i = 1, res[4];

    if (arr[0] == x)
        return 0;

    while (i < n && arr[i] <= x)
        i = i * 2;

    n = min(i, n - 1);
    int mod = n % 4;

    for (int j = 0, part = n / 4; j < 4; j++)//creacion de los 4 hilos que haran la busqueda binaria
    {
        struct bin_args arg;
        pthread_t thread;
        threads[j] = thread;
        arg.arr = arr;
        arg.x = x;
        arg.l = part * j;
        if (mod != 0 && j == 3)
            arg.r = part * (j + 1) - 1 + mod;
        else
            arg.r = part * (j + 1) - 1;

        res[j] = pthread_create(&threads[j], NULL, &binarySearch, (void *)&arg);
        pthread_join(threads[j], NULL);
    }
}

int main(int argc, char *argv[])
{
    //int arr[] = {2, 3, 4, 10, 30, 40, 60, 70, 90, 100, 120, 240};
    //int n = sizeof(arr) / sizeof(arr[0]);
    //int x = 30;
    double utime0, stime0, wtime0, utime1, stime1, wtime1; //medicion del tiempo
    int i;                                                 //variabke de loops
    int n;                                                 // tamaño del problema
    int *A;                                                //Arreglo del archivo
    //Areglo de búsqueda
    int B[] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 1295390003, 450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666, 2147470852, 0};

    //Recepción y decodificación de argumentos
    //******************************************************************

    //Si no se introducen exactamente 2 argumentos (Cadena de ejecución ,cadena=n)
    if (argc != 2)
    {
        printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100 \n", argv[0]);
        exit(1);
    }
    //Tomar el segundo argumento como tamaño n

    n = atoi(argv[1]);

    // Lectura del archivo 10millones(ord-des).txt mediante redireccionamiento.

    A = (int *)malloc(sizeof(int) * n); //calculo de la memoria necesaria para el arreglo segun la n

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        //printf("[%d]=%d\n", i, A[i]);
    }
    //*******************************************************************************************************
    printf("\n****Busqueda Exponencial hilos****\n");
    int q = sizeof(A) / sizeof(A[0]);
    for (i = 0; i < 20; i++)
    {
        printf("Numero a encontrar:%d\n", B[i]);
        uswtime(&utime0, &stime0, &wtime0); //inicio del conteo de tiempo
        exponentialSearch(A, q, B[i]);
        uswtime(&utime1, &stime1, &wtime1); //termino del conteo de tiempo
        //Cálculo del tiempo de ejecución del programa
        printf("\n");
        printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
        printf("user (Tiempo de procesamiento en CPU's) %.10f s\n", utime1 - utime0);
        printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", 4, (utime1 - utime0) / 4);
        printf("sys (Tiempo en acciónes de E/S)  %.3f s\n", stime1 - stime0);
        printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
        printf("\n");
    }

    return 0;
}
