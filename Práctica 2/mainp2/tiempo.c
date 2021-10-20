//*****************************************************************
//Datos del Código base
//M. EN C. EDGARDO ADRIÁN FRANCO MARTÍNEZ
//Curso: Análisis de algoritmos
//(C) Enero 2013
//ESCOM-IPN
//*****************************************************************
//Datos del Código Actual
/*
Versión del programa: 1.0

Nombre del programa: Algoritmos de búsqueda de datos en lenguaje c

Descripción:
Este programa recibe el tamaño de problema -n-, recibe la opc (1-5) que selecciona
que algoritmo de búsqueda se usara, si es 1 es búsqueda lineal, y así sucesivamente,
y al correrlo desde el script, se redireccionara a un archivo txt donde se mostrara 
que algoritmo hizo la búsqueda, si se encuentra el dato del arreglo de búsqueda en 
el archivo de la práctica (según sea el caso) y cuanto tiempo le tomo al algoritmo
hacer la búsqueda

Errores:
El Árbol muere cuando el tamaño del problema es mayor a los 2 millones

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
gcc main.c tiempo.c -o sal
*/
//*****************************************************************
//Librerias incluidas
//*****************************************************************
#include <sys/resource.h>
#include <stdio.h>
#include <sys/time.h>
#include "tiempo.h"
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
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

//*****************************Algoritmos de Búsqueda*****************************************************
//Algoritmo de búsqueda lineal
int search(int arr[], int n, int x) //Recibe un arreglo, el tamaño -n- y el dato a buscar
{
    int i;
    for (i = 0; i < n; i++) // Recorre el arreglo desde la pos 0 hasta n-1 comparando el dato a buscar con el
        if (arr[i] == x)    // dato de la pos del arreglo
            return i;       // si lo encuentra regresa la pos en la que se encuetra en el arreglo
    return -1;              // si no lo encuentra regresa un -1
}

//Búsqueda exponencial
int exponentialSearch(int arr[], int n, int x) //Recibe un arreglo, el tamaño -n- y el dato a buscar
{
    // pregunta si esta en la posición 0
    if (arr[0] == x)
        return 0;

    // si no esta busca aproximarse a donde se encuentra el valor que se busca sin pasarse
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i * 2; //crecimiento exponencial del indice

    return binarySearch(arr, i / 2, MIN(i, n - 1), x); //con el indice aproximado hace una búsqueda binaria
}

/*Esta función se encarga de dividir un arreglo a la mitad y verificar si el numero buscado es igual al que se 
encuentra a la mitad del arreglo o si es menor o mayor, si es menor se trabajara con la mitad izquierda
del arreglo y ssi es mayor se utilizara la mitad derecha, posteriormente se vuelve a divir a la mitad la 
parte en la que se cree que se encuentra el numero y se vulven a hacer las comparaciones antes mencionadas y
asi sucesivamente hasta encontrar el numero o terminar de analizar los valores en el arreglo*/
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x) //Se verifica si el valor buscado esta en la m-esima posicion
            return m;

        // If x greater, ignore left half

        if (arr[m] < x) //Se verifica si el valor buscado es mayor al valor en la m-esima posicion
            l = m + 1;  //Se delimita la parte izquierda del nuevo arreglo a analizar, para descartar los valores en donde no se encuentra el valor buscado
        // If x is smaller, ignore right half
        else           //Se verifica si el valor buscado es menor al valor en la m-esima posicion
            r = m - 1; //Se delimita la parte derecha del nuevo arreglo a analizar, para descartar los valores en donde no se encuentra el valor buscado
    }
    // if we reach here, then element was
    // not present
    return -1;
}

//Busqueda de Fibo
int min(int x, int y) { return (x <= y) ? x : y; }
 
int fibMonaccianSearch(int arr[], int x, int n)
{
    /* Inicializaci�n de la serie de Fibonacci hasta n */
    int fibMMm2 = 0;  
    int fibMMm1 = 1; 
    int fibM = fibMMm2 + fibMMm1; 
 
    /* fibM va a almacenar el Fibonacci m�s peque�o
       N�mero mayor o igual a n */
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
 
    // Marca el rango eliminado desde el inicio
    int offset = -1;
 
    /* mientras que hay elementos a recorrer, comparamos arr [fibMm2] con x.
	Cuando fibM se convierte en 1,fibMm2 se convierte en 0*/
    while (fibM > 1) {
       
        int i = min(offset + fibMMm2, n - 1);
 
        
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
 
        /* Elemento encontrado, regresamos su posici�n */
        else
            return i;
    }
 
   
    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;
 
    /*Elemento no encontrado */
    return -1;
}