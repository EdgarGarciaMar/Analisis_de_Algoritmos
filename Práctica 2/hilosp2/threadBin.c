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
gcc threadBin.c tiempo.c -o sal -lpthread
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "tiempo.h"
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int NumThreads; //Número de threads
int N, j;       // N es el tamaño del problema, j es un iterador auxiliar
int *A;         //Arreglo del archivo
//Areglo de búsqueda
int B[] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 1295390003, 450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666, 2147470852, 0};
//****Estructura que almacenara los valores con los que trabajara el algoritmo****
struct args_thread
{
    int *arr;
    int l, r, x, th_n;
};
//****Declaracion de la FUNCION DE BUSQUEDA BINARIA****
void *busquedaBinaria(void *args){
    struct args_thread *argumentos = args;
    int *arr;
    int l, r, x, result = -1, th_n;
    arr = argumentos->arr;
    l = argumentos->l;
    r = argumentos->r;
    x = argumentos->x;
    
    //printf("Soy el hilo %d\n", argumentos->th_n);

    while (l <= r) {
        int m = l + (r - l) / 2;
  		
        // Check if x is present at mid
        if (arr[m] == x){//Se verifica si el valor buscado esta en la m-esima posicion
            result = m;
	    //printf("El elemento se encuentra en el hilo %d\n", argumentos->th_n);
            break;
        }
  
        // If x greater, ignore left half
    
        if (arr[m] < x)//Se verifica si el valor buscado es mayor al valor en la m-esima posicion
            l = m + 1;//Se delimita la parte izquierda del nuevo arreglo a analizar, para descartar los valores en donde no se encuentra el valor buscado
        // If x is smaller, ignore right half
        else//Se verifica si el valor buscado es menor al valor en la m-esima posicion
            r = m - 1;//Se delimita la parte derecha del nuevo arreglo a analizar, para descartar los valores en donde no se encuentra el valor buscado
    }
    // if we reach here, then element was
    // not present
    //return -1;
    (result == -1) ? printf("Element is not present"
                            " in array\n")
                   : printf("Element is present at "
                            "index %d\n", result);
	pthread_detach(pthread_self()); 
	pthread_exit(0);
}

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int argc, char const *argv[])
{
    double utime0, stime0, wtime0, utime1, stime1, wtime1;   
    //Si no se introducen exactamente 2 argumentos (Cadena de ejecución, cadena=n)
    if (argc != 2)
    {
        printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100 \n", argv[0]);
        exit(1);
    }
    //Tomar el segundo argumento como tamaño n
    N = atoi(argv[1]);
    // Lectura del archivo 10millones(ord-des).txt mediante redireccionamiento.

    A = (int *)malloc(sizeof(int) * N); //calculo de la memoria necesaria para el arreglo segun la n

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    //int arr[] = { 2, 3, 4, 10, 40 };
    //int tamano_arr = sizeof(arr) / sizeof(arr[0]);
    NumThreads = (int)(log(sizeof(A)/4.00) / log(2));
    pthread_t hilos[NumThreads];
    int modulo, fact_comun;
    struct args_thread argumentos;
    argumentos.arr = A;
    //argumentos.x = x;
    modulo = N % NumThreads;
    fact_comun = N / NumThreads;

	//printf("numero de hilos %d, tamano arr = %d\n", n_hilos, tamano_arr);
	//printf("valor del log %f\n", log(sizeof(arr)/4.00));

    //ciclo  para la búsqueda de cada número
    printf("\n****Busqueda BINARIA****\n");
    for (j = 0; j < 20; j++)
    {
        printf("Numero a encontrar:%d\n", B[j]);
        uswtime(&utime0, &stime0, &wtime0); //inicio del conteo de tiempo
        argumentos.x = B[j];
        //Crear los threads con la función "busquedaBinaria" que realiza la búsqueda binaria
        for (int i = 0; i < NumThreads; i++)
        {
            pthread_t hiloBaby;
            hilos[i] = hiloBaby; 
            argumentos.l = fact_comun*i;
            argumentos.th_n = i;
            if (modulo == 0)
            {
                argumentos.r = fact_comun*(i + 1) - 1;
            }else{
                argumentos.r = fact_comun*(i + 1) - 1 + modulo;
            }
            pthread_create(&hilos[i], NULL, &busquedaBinaria, (void *)&argumentos);
	        //printf("Soy el hilo %d\n", i);
            pthread_join(hilos[i], NULL);        
        }
    } 

     uswtime(&utime1, &stime1, &wtime1); //termino del conteo de tiempo
        //Cálculo del tiempo de ejecución del programa
        printf("\n");
        printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
        printf("user (Tiempo de procesamiento en CPU's) %.10f s\n", utime1 - utime0);
        printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", NumThreads, (utime1 - utime0) / NumThreads);
        printf("sys (Tiempo en acciónes de E/S)  %.3f s\n", stime1 - stime0);
        printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
        printf("\n");   
    return 0;
}
