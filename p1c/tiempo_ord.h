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

Nombre del programa: Algoritmos de ordenamiento de datos en lenguaje c

Descripción:
Este programa recibe el tamaño de problema -n-, la opción de ordenamiento del 1-9 
las cuales son burbuja, inserción, selección, etc. Y mediante redireccionamiento toma el -n- 
conjunto de números del archivo numeros10millones.txt, la salida es redireccionada a un archivo 
txt donde se muestra que algoritmo ordeno los números, y muestra el tiempo real, del sistema y 
del usuario que le tomo a la pc para realizar dicha operación e imprime los datos ordenados.

Errores:
El programa puede marcar error si la cantidad de números ingresada es muy grande.

Equipo: Noobcoders
Fuentes Díaz Jesús Alejandro
García Ledezma Miguel Ángel
García Marciano Edgar
Guadarrama Hidalgo Jorge Luis
Práctica 1
Pruebas a posteriori
Análisis de algoritmos
Franco Martínez Edgardo Adrián
3CM12

compilación:
gcc main.c tiempo_ord.c -o sal
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

//Funciones de Ordenamiento
/*En este apartado se declaran las funciones de ordenamiento que seran utilizadas en el main
la descripción de estas funciones se encuentra en  el archivo de implementación tiempo_ord.c
*/
void BurbujaSimple(int A[], int n);

void Burbujaop1(int A[], int n);

void Burbujaop2(int A[], int n);

void insercion(int *, int);

void seleccion(int *, int);

void shell(int A[], int n);

void MergeSort(int *A, int p, int r);
void Merge(int *A, int p, int q, int r);

void QuickSort(int *A, int p, int r);
int Pivot(int *A, int p, int r);
void Intercambiar(int *A, int i, int j);