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
//uswtime (Declaración)
//*****************************************************************
//Descripción: Función que almacena en las variables referenciadas
//el tiempo de CPU, de E/S y Total actual del proceso actual.
//
//Recibe: Variables de tipo doble para almacenar los tiempos actuales
//Devuelve:
//*****************************************************************
void uswtime(double *usertime, double *systime, double *walltime);
/* 
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


//*****************************Declaraciones de los Algoritmos de Búsqueda*****************************************************
int search(int arr[], int n, int x);

int exponentialSearch(int arr[], int n, int x);

int binarySearch(int arr[], int l, int r, int x);

int min(int x, int y);

int fibMonaccianSearch(int arr[], int x, int n);