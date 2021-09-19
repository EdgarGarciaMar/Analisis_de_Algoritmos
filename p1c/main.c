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
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo_ord.h"
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************
//Estructura del árbol binario, se contempla la raiz, hijo izq, hijo der y su dato
struct arbol
{
	struct arbol *der, *izq;
	int dato;
};

int pos = 0;				//variable que controla la posición en el arreglo cuando se guardan los datos del árbol
struct arbol *vacio = NULL; //Vacío de referencia
//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
/*
Arbol binario
*/
void insertarbol(struct arbol **raiz, int num) //Función que guarda los datos en el arbol
{
	if ((*raiz) == NULL) //Cuando esta vacio el arbol se crea la raiz con sus hijos vacios
	{
		*raiz = malloc(sizeof(struct arbol));
		(*raiz)->dato = num;
		(*raiz)->der = NULL;
		(*raiz)->izq = NULL;
	}
	else //cuando se tiene raiz se guarda conforme al tamaño, si es menor se guarda en izq, si es mayor en la der
	{
		if (num < (*raiz)->dato)
		{
			insertarbol(&(*raiz)->izq, num);
		}
		else
		{
			insertarbol(&(*raiz)->der, num);
		}
	}
}

void guardarRecorridoinorden(struct arbol *raiz, int A[]) //función de guardado en el arreglo
{
	if (raiz != vacio)
	{
		//se recorre el árbol en inorden, se van guardando los numeros acorde a pos en el arreglo
		//Siempre y cuando no este vacía la raiz
		guardarRecorridoinorden(raiz->izq, A);
		A[pos++] = raiz->dato;
		guardarRecorridoinorden(raiz->der, A);
	}
}

void ordenamientodearbolbinario(int A[], int n) //Función de ordenamiento
{
	struct arbol *arbol = NULL;
	for (int i = 0; i < n; i++)
	{
		insertarbol(&arbol, A[i]); //Se guardan los datos en árbol
	}
	guardarRecorridoinorden(arbol, A); //Se guardan los datos en A[]
	free(arbol);
}
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int argc, char *argv[])
{
	//******************************************************************
	//Variables del main
	//******************************************************************
	double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
	int n, opc;											   //n determina el tamaño del algorito dado por argumento al ejecutar
	int i;												   //Variables para loops

	//******************************************************************
	//Recepción y decodificación de argumentos
	//******************************************************************

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc != 3)
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100 1\n", argv[0]);
		exit(1);
	}
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n = atoi(argv[1]);
		opc = atoi(argv[2]);
	}
	// Lectura del archivo numeros10millones.txt mediante redireccionamiento.
	int A[n];
	for (int a = 0; a < n; a++)
	{
		scanf("%d", &A[a]);
		//printf("[%d]=%d\n", a, A[a]);
	}
	//******************************************************************
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************
	switch (opc)
	{
	case 1: //burbuja Simple
		uswtime(&utime0, &stime0, &wtime0);
		BurbujaSimple(A, n);
		uswtime(&utime1, &stime1, &wtime1);
		printf("\n**********Burbuja Simple***********\n");
		break;
	case 2: //Burbuja op1
		uswtime(&utime0, &stime0, &wtime0);
		Burbujaop1(A, n);
		uswtime(&utime1, &stime1, &wtime1);
		printf("\n**********Burbuja optimizada 1***********\n");
		break;
	case 3: //burbuja op2
		uswtime(&utime0, &stime0, &wtime0);
		Burbujaop2(A, n);
		uswtime(&utime1, &stime1, &wtime1);
		printf("\n**********Burbuja optimizada 2***********\n");
		break;
	case 4: //insercion
		uswtime(&utime0, &stime0, &wtime0);
		insercion(A, n);
		uswtime(&utime1, &stime1, &wtime1);
		printf("\n**********Insercion***********\n");
		break;
	case 5: //seleccion
		uswtime(&utime0, &stime0, &wtime0);
		seleccion(A, n);
		uswtime(&utime1, &stime1, &wtime1);
		printf("\n**********Seleccion***********\n");
		break;
	case 6: //shell
		uswtime(&utime0, &stime0, &wtime0);
		shell(A, n);
		uswtime(&utime1, &stime1, &wtime1);
		printf("\n**********Shell***********\n");
		break;
	case 7: //Árbol binario
		uswtime(&utime0, &stime0, &wtime0);
		ordenamientodearbolbinario(A, n);
		uswtime(&utime1, &stime1, &wtime1);
		printf("\n**********Arbol binario***********\n");
		break;
	case 8: //ordenamiento por mezcla
		uswtime(&utime0, &stime0, &wtime0);
		MergeSort(A, 0, n - 1);
		uswtime(&utime1, &stime1, &wtime1);
		printf("\n**********Ordenamiento por mezcla***********\n");
		break;
	case 9: //ordenamiento rapido
		uswtime(&utime0, &stime0, &wtime0);
		QuickSort(A, 0, n - 1);
		uswtime(&utime1, &stime1, &wtime1);
		printf("\n**********Ordenamiento rapido***********\n");
		break;
	default:
		printf("\n Error opc.\n");
		exit(1);
		break;
	}
	//uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************

	//******************************************************************
	//Algoritmo
	//******************************************************************
	//for (i = 0; i < n; i++)
	//	for (i = 0; i < n; i++)
	//		n = n;
	//******************************************************************

	//******************************************************************
	//Evaluar los tiempos de ejecución
	//******************************************************************
	// uswtime(&utime1, &stime1, &wtime1);

	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
	//*************Imprimir el arreglo ordenado*********************************
	printf("\n opc = %d , Los numeros ordenados son:\n", opc);
	for (int a = 0; a < n; a++)
	{
		printf("[%d]= %d\n", a, A[a]);
	}
	//Terminar programa normalmente
	exit(0);
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES
//************************************************************************
