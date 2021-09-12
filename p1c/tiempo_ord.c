//*****************************************************************
//TIEMPO.C
//*****************************************************************
//*****************************************************************
//M. EN C. EDGARDO ADRIÁN FRANCO MARTÍNEZ
//Curso: Análisis de algoritmos
//(C) Enero 2013
//ESCOM-IPN
//Ejemplo de medición de tiempo en C y recepción de parametros en C bajo UNIX
//Compilación de la libreria: "gcc -c tiempo.c " (Generación del código objeto)
//*****************************************************************

//*****************************************************************
//Librerias incluidas
//*****************************************************************
#include <sys/resource.h>
#include <sys/time.h>
#include "tiempo_ord.h"
#include <stdio.h>
#include <stdlib.h>
//*****************************************************************
//uswtime (Definición)
//*****************************************************************
//Descripción: Función que almacena en las variables referenciadas
//el tiempo de CPU, de E/S y Total actual del proceso actual.
//
//Recibe: Variables de tipo doble para almacenar los tiempos actuales
//Devuelve:
//*****************************************************************#include <stdio.h>
void uswtime(double *usertime, double *systime, double *walltime)
{
    double mega = 1.0e-6;
    struct rusage buffer;
    struct timeval tp;
    struct timezone tzp;
    getrusage(RUSAGE_SELF, &buffer);
    gettimeofday(&tp, &tzp);
    *usertime = (double)buffer.ru_utime.tv_sec + 1.0e-6 * buffer.ru_utime.tv_usec;
    *systime = (double)buffer.ru_stime.tv_sec + 1.0e-6 * buffer.ru_stime.tv_usec;
    *walltime = (double)tp.tv_sec + 1.0e-6 * tp.tv_usec;
}

/*En Unix, se dispone de temporizadores ejecutables (en concreto time) que nos proporcionan medidas de los tiempos
de ejecución de programas. Estos temporizadores nos proporcionan tres medidas de tiempo:

    * real:  Tiempo real que se ha tardado desde que se lanzó el programa a ejecutarse hasta que el programa finalizó y proporcionó los resultados.
    * user: Tiempo que la CPU se ha dedicado exclusivamente a la computación del programa.
    * sys: 	Tiempo que la CPU se ha dedicado a dar servicio al sistema operativo por necesidades del programa (por ejemplo para llamadas al sistema para efectuar I/O).

El tiempo real también suele recibir el nombre de elapsed time o wall time. Algunos temporizadores también proporcionan el porcentaje de tiempo que la CPU se ha dedicado al programa. Este porcentaje viene dado por la relación entre el tiempo de CPU (user + sys)
y el tiempo real, y da una idea de lo cargado que se hallaba el sistema en el momento de la ejecución del programa.

El grave inconveniente de los temporizadores ejecutables es que no son capaces de proporcionar medidas de tiempo de ejecución de segmentos de código. Para ello, hemos de invocar en nuestros propios programas  a un conjunto de temporizadores disponibles en la mayor parte de las librerías de C de Unix, que serán los que nos proporcionen medidas sobre los tiempos de ejecución de trozos discretos de código.

En nuestras prácticas vamos a emplear una función que actúe de temporizador y que nos proporcione los tiempos de CPU (user, sys)
y el tiempo real. En concreto, vamos a emplear el procedimiento uswtime listado a continuación. 

Este procedimiento en realidad invoca a dos funciones de Unix: getrusage y gettimeofday. La primera de ellas nos proporciona el tiempo de CPU, tanto de usuario como de sistema, mientras que la segunda nos proporciona el tiempo real (wall time). Estas dos funciones son las que disponen de mayor resolución de todos los temporizadores disponibles en Unix.
 
Modo de Empleo:
 
La función uswtime se puede emplear para medir los tiempos de ejecución de determinados segmentos de código en nuestros programas. De forma esquemática, el empleo de esta función constaría de los siguientes pasos:

    1.- Invocar a uswtime para fijar el instante a partir del cual se va a medir el tiempo.

            uswtime(&utime0, &stime0, &wtime0);

    2.- Ejecutar el código cuyo tiempo de ejecución se desea medir.
    3.- Invocar a uswtime para establecer el instante en el cual finaliza la medición
        del tiempo de ejecución.

            uswtime(&utime1, &stime1, &wtime1);

    4.- Calcular los tiempos de ejecución como la diferencia entre la primera y segunda
        invocación a uswtime:

            real:   wtime1 - wtime0
            user:   utime1 - utime0
            sys :   stime1 - stime0

            El porcentaje de tiempo dedicado a la ejecución de ese segmento de código
            vendría dado por la relación CPU/Wall:

	CPU/Wall = (user + sys) / real x 100 %*/

//*************************Metodos de ordenamiento********************************************

/*
Burbuja Simple:
Esta función recibe como argumentos el arreglo a ordenar y el tamaño del arreglo que es n, ademas n es de
igual forma el tamaño del problema.
Variables:
-i,j son de los bucles
-aux es el auxiliar para hacer el ordenamiento

El algoritmo consiste de 2 ciclos for, el primero va de 0 a n-2, el segundo va de 0 a n-1 y en su interior
se encuentra un if el cual hace las comprobaciones de cual es el numero menor, para regresar el arreglo 
ordenado del número menor al mayor.
*/
void BurbujaSimple(int A[], int n)
{
    int aux;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
        }
    }
}
/*
Burbuja optimizada 1:
Esta función recibe como argumentos el arreglo a ordenar y el tamaño del arreglo que es n, ademas n es de
igual forma el tamaño del problema.
Variables:
-i,j para los bucles
-aux variable auxiliar en los cambios en el ordenamiento.

El algoritmo de igual forma consiste en dos ciclos for, el primero va de 0 a n-1, el segundo va de 0 a (n-1)
- el valor del iterador i, lo cual hace reducir el numero de ciclos, este algoritmo de igual forma nos devuelve
el arreglo ordenado del número menor al mayor.
*/
void Burbujaop1(int A[], int n)
{
    int aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - 1) - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
        }
    }
}
/*
Burbuja optimizada 2:
Esta función recibe como argumentos el arreglo a ordenar y el tamaño del arreglo que es n, ademas n es de
igual forma el tamaño del problema.
Variables:
-i,j para los bucles
-aux variable auxiliar en los cambios en el ordenamiento.
cambios variable que actua como bandera indica cuando ya no se cumple el for para terminar el while

El algoritmo consiste de  un  ciclo while que se ejecutara mientras i sea menor o igual a n-2 y cambios diferente
de N, luego se tiene un ciclo for desde 0  hasta (n-1)-i, después se evaluaa un if que busca el numero mayor, por lo
que devuelve el arreglo ordenado de mayor a menor.
*/
void Burbujaop2(int A[], int n)
{
    int aux;
    char cambios = 'S';
    int i = 0;

    while (i <= n - 1 && cambios != 'N')
    {
        cambios = 'N';
        for (int j = 0; j < (n - 1) - i; j++)
        {
            if (A[j] < A[j + 1])
            {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
                cambios = 'S';
            }
        }
        i = i + 1;
    }
}

void insersion(int A[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        j = i;
        temp = A[i];
        while (j > 0 && temp < A[j - 1])
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
}
void seleccion(int A[], int n)
{
    int k, p, i, temp;
    for (k = 0; k < n - 2; k++)
    {
        p = k;
        for (i = k + 1; i < n - 1; i++)
        {
            if (A[i] < A[p])
            {
                p = i;
            }
        }
        temp = A[p];
        A[p] = A[k];
        A[k] = temp;
    }
}