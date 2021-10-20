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
gcc hilo.c tiempo.c -o sal -lpthread
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int NumThreads; //Número de threads
int N, j;       // N es el tamaño del problema, j es un iterador auxiliar
int *A;         //Arreglo del archivo
//Areglo de búsqueda
int B[] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 1295390003, 450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666, 2147470852, 0};

//********************************************************************************
//DECLARACION DE FUNCIONES

void *procesar(void *id)
{
    int n_thread = (int)id;
    int inicio, fin; // Varaibles para delimitar el arreglo por hilos

    //Asignación del interavlo a atrabajar a l hilo
    inicio = (n_thread * N) / NumThreads;
    if (n_thread == NumThreads - 1)
        fin = N;
    else
        fin = ((n_thread + 1) * N) / NumThreads - 1;

    printf("\nThread %d\tInicio %d\tTermino %d", n_thread, inicio, fin);
    //Con el intervalo de trabajo del hilo, se hace la busquedalineal y muestra si encontro el dato o no 
    int res = busquedaLineal(A, inicio, fin, B[j]);
    if (res != -1)
    {
        printf("\n***El numero %d esta en la posicion %d del hilo %d***\n", B[j], res, n_thread);
    }
    else
    {
        printf("\n**El numero %d no esta***\n", B[j]);
    }

    if (n_thread != 0)
    {
        pthread_exit(0); //Termina el hilo, a excepcion del main.
    }
}

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int argc, char *argv[])
{
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    int i = 0; //Variables auxiliares para loops

    //********************************************************************************
    //Obtener el número de threads a usar y guardar el intervalo de numeros en el arreglo
    //********************************************************************************
    pthread_t *thread;

    //Recepción y decodificación de argumentos
    //******************************************************************

    //Si no se introducen exactamente 3 argumentos (Cadena de ejecución , Número de hilos ,cadena=n)
    if (argc != 3)
    {
        printf("\nIndique el numero de hilos y el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 4 100 \n", argv[0]);
        exit(1);
    }
    //Tomar el segundo argumento como número de hilos y el 3 como tamaño n

    NumThreads = atoi(argv[1]);
    thread = malloc(NumThreads * sizeof(pthread_t));
    N = atoi(argv[2]);

    // Lectura del archivo 10millones(ord-des).txt mediante redireccionamiento.

    A = (int *)malloc(sizeof(int) * N); //calculo de la memoria necesaria para el arreglo segun la n

    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
        //printf("[%d]=%d\n", i, A[i]);
    }
    //*******************************************************************************************************

    i = 0;
    //ciclo  para la búsqueda de cada número
    printf("\n****Busqueda lineal****\n");
    for (j = 0; j < 20; j++)
    {
        printf("Numero a encontrar:%d\n", B[j]);
        uswtime(&utime0, &stime0, &wtime0); //inicio del conteo de tiempo

        //Crear los threads con la función "procesar" que realiza la búsqueda lineal
        for (i = 1; i < NumThreads; i++)
        {
            if (pthread_create(&thread[i], NULL, procesar, (void *)i) != 0)
            {
                perror("El thread no pudo crearse");
                exit(-1);
            }
        }
        //El main ejecuta el thread 0
        procesar(0);

        //Esperar a que terminen los threads 
        for (i = 1; i < NumThreads; i++)
        {
            pthread_join(thread[i], NULL); //Espera a los hilos
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
    }

    //Terminar programa*/
    exit(0);
}
