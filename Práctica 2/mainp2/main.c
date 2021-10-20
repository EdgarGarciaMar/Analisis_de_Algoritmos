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
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************
typedef struct nodo
{
	int dato;
	int altura; //Indica de que lado esta cargado el nodo
	struct nodo *hijoIzquierdo;
	struct nodo *hijoDerecho;
} Nodo;
//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
/////////////////////////////////////////////////////////////// Funciones del arbol balanceado inicio //////////////////////////////////////////////////////////////////////

int altura(Nodo *r)
{ //Devuelve la altura de un nodo, se usa en el reacomodo de nodos
	if (r == NULL)
		return -1;
	else
		return r->altura;
}

int max(int a, int b)
{ //Devuelve el mayor de 2 numeeros esta funcio es usada para la inserccion de un nodo y las rotaciones
	return a > b ? a : b;
}

Nodo *rotacion_der(Nodo *r)
{ //Realiza una rotacion simple a la derecha
	Nodo *temp;
	temp = r->hijoDerecho;
	r->hijoDerecho = temp->hijoIzquierdo;
	temp->hijoIzquierdo = r;
	r->altura = max(altura(r->hijoIzquierdo), altura(r->hijoDerecho)) + 1;
	temp->altura = max(altura(temp->hijoDerecho), r->altura) + 1;
	return temp;
}

Nodo *rotacion_izq(Nodo *r)
{ //Realiza una rotacion simple a la izquierda
	Nodo *temp;
	temp = r->hijoIzquierdo;
	r->hijoIzquierdo = temp->hijoDerecho;
	temp->hijoDerecho = r;
	r->altura = max(altura(r->hijoDerecho), altura(r->hijoIzquierdo)) + 1;
	temp->altura = max(altura(temp->hijoIzquierdo), r->altura) + 1;
	return temp;
}

Nodo *rot_doble_izq(Nodo *r)
{ //Realiza una rotacion compuesta a la izquierda
	r->hijoIzquierdo = rotacion_der(r->hijoIzquierdo);
	return rotacion_izq(r);
}

Nodo *rot_doble_der(Nodo *r)
{ //Realiza una rotacion sompuesta a la derecha
	r->hijoDerecho = rotacion_izq(r->hijoDerecho);
	return rotacion_der(r);
}

Nodo *nuevo()
{ //Crea un nuevo nodo y duevulve su apuntador
	Nodo *temp = (Nodo *)malloc(sizeof(Nodo));
	if (temp == NULL)
	{
		exit(0);
	}
	return temp;
}

Nodo *insertar(int dato, Nodo *r)
{ //Inserta un nuevo nodo al arbol
	if (r == NULL)
	{
		r = nuevo();
		r->dato = dato;
		r->altura = 0;
		r->hijoDerecho = NULL;
		r->hijoIzquierdo = NULL;
	}
	else if (dato < r->dato)
	{
		r->hijoIzquierdo = insertar(dato, r->hijoIzquierdo);
		if (altura(r->hijoIzquierdo) - altura(r->hijoDerecho) == 2)
			if (dato < r->hijoIzquierdo->dato)
				r = rotacion_izq(r);
			else
				r = rot_doble_izq(r);
	}
	else if (dato > r->dato)
	{
		r->hijoDerecho = insertar(dato, r->hijoDerecho);
		if (altura(r->hijoDerecho) - altura(r->hijoIzquierdo) == 2)
			if (dato > r->hijoDerecho->dato)
				r = rotacion_der(r);
			else
				r = rot_doble_der(r);
	}
	else
	{
		return r; //En caso de que un valor ya se encuentre en el arbol
	}

	r->altura = max(altura(r->hijoIzquierdo), altura(r->hijoDerecho)) + 1;
	return r;
}

int alturaarbol(Nodo *r)
{ //Retorna la altura del arbol
	int izq;
	int der;
	if (r == NULL)
		return 0;
	izq = altura(r->hijoIzquierdo) + 1;
	der = altura(r->hijoDerecho) + 1;
	if (izq > der)
		return izq;
	else if (izq < der)
		return der;
	else
		return der;
}

/////////////////////////////////////////////////////////////// Funciones del arbol balanceado Fin //////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////// Funciones Busqueda ABB inicio //////////////////////////////////////////////////////////////////////
void BusquedaABB(Nodo *r, int dato)
{ //La funcion busqueda imprime si el elemento fue o no encontrado en el arbol
	Nodo *temp = r;
	while (r != NULL)
	{
		if (dato < r->dato)
		{
			r = r->hijoIzquierdo;
		}
		else if (dato > r->dato)
		{
			r = r->hijoDerecho;
		}
		else
		{
			printf("El elemento se encuentra en el arbol.\n");
			return;
		}
	}
	printf("El elemento no se encuentra en el arbol.\n");
	return;
}
/////////////////////////////////////////////////////////////// Funciones Busqueda ABB fin //////////////////////////////////////////////////////////////////////

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
	int n, opc;											   //n determina el tamaño del algorito dado por argumento al ejecutar y la opc es la seleccion del algorimto
	int recorrido_b;									   //Pos de Dato a buscar
	int *A;												   //Arreglo del archivo
	int res;											   //Variable de reultado, la cual es verificada
	int a;												   //variable de loop
	//Areglo de búsqueda
	int b[] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 1295390003, 450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666, 2147470852, 0};
	//******************************************************************
	//Recepción y decodificación de argumentos
	//******************************************************************

	//Si no se introducen exactamente 3 argumentos (Cadena de ejecución , cadena=n, opción)
	if (argc != 3)
	{
		printf("\nIndique el tamanio del algoritmo y la opcion - Ejemplo: [user@equipo]$ %s 100 1 \n", argv[0]);
		exit(1);
	}
	//Tomar el segundo argumento como tamaño del algoritmo y el 3 la opc
	else
	{
		n = atoi(argv[1]);
		opc = atoi(argv[2]);
	}

	// Lectura del archivo 10millones(ord-des).txt mediante redireccionamiento.

	A = (int *)malloc(sizeof(int) * n); //calculo de la memoria necesaria para el arreglo segun la n

	for (a = 0; a < n; a++)
	{
		scanf("%d", &A[a]);
		//printf("[%d]=%d\n", a, A[a]);
	}
	//******************************************************************
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	switch (opc)
	{
	case 1:
		printf("\n****Busqueda lineal****\n");
		for (recorrido_b = 0; recorrido_b < 20; recorrido_b++)
		{
			uswtime(&utime0, &stime0, &wtime0);
			res = search(A, n, b[recorrido_b]);
			uswtime(&utime1, &stime1, &wtime1);
			if (res == -1)
			{
				printf("\nEl numero %d no esta \n", b[recorrido_b]);
			}
			else
			{
				printf("\nEl numero %d esta en la posicion %d \n", b[recorrido_b], res);
			}
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
		}
		break;
	case 2:
		printf("\n****Busqueda en ABB****\n");
		for (recorrido_b = 0; recorrido_b < 20; recorrido_b++)
		{
			//Para llamar crear el arbol usar esta linea de codigo
			Nodo *raiz = NULL; //El nodo raiz puede ser declarado en la funcion main solo tiene que ser enviada
			for (a = 0; a < n; a++)
			{
				raiz = insertar(A[a], raiz);
			}
			uswtime(&utime0, &stime0, &wtime0);
			//para llamar a buqueda usar la siguiente linea de codigo.
			BusquedaABB(raiz, b[recorrido_b]); //La misma funcion imprime si se encontro o no el valor
			uswtime(&utime1, &stime1, &wtime1);
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
		}
		break;
	case 3:
		printf("\n****Busqueda binaria****\n");
		for (recorrido_b = 0; recorrido_b < 20; recorrido_b++)
		{
			uswtime(&utime0, &stime0, &wtime0);
			res = binarySearch(A, 0, n - 1, b[recorrido_b]);
			uswtime(&utime1, &stime1, &wtime1);
			if (res == -1)
			{
				printf("\nEl numero %d no esta \n", b[recorrido_b]);
			}
			else
			{
				printf("\nEl numero %d esta en la posicion %d \n", b[recorrido_b], res);
			}
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
		}
		break;
	case 4:
		printf("\n****Busqueda exponencial****\n");
		for (recorrido_b = 0; recorrido_b < 20; recorrido_b++)
		{
			uswtime(&utime0, &stime0, &wtime0);
			res = exponentialSearch(A, n, b[recorrido_b]);
			uswtime(&utime1, &stime1, &wtime1);
			if (res == -1)
			{
				printf("\nEl numero %d no esta \n", b[recorrido_b]);
			}
			else
			{
				printf("\nEl numero %d esta en la posicion %d \n", b[recorrido_b], res);
			}
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
		}
		break;
	case 5:
		printf("\n****Busqueda Fibonacci****\n");
		for (recorrido_b = 0; recorrido_b < 20; recorrido_b++)
		{
			uswtime(&utime0, &stime0, &wtime0);
			res = fibMonaccianSearch(A, b[recorrido_b], n);
			uswtime(&utime1, &stime1, &wtime1);
			if (res == -1)
			{
				printf("\nEl numero %d no esta \n", b[recorrido_b]);
			}
			else
			{
				printf("\nEl numero %d esta en la posicion %d \n", b[recorrido_b], res);
			}
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
		}

		break;
	default:
		printf("\n****Error en opc, selecciona una de las 5 opciones****\n");
		break;
	}
	//******************************************************************
	//uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************

	//******************************************************************
	//Algoritmo
	//******************************************************************
	/*for(i=0;i<n;i++)
		for(i=0;i<n;i++)
			n=n;*/
	//******************************************************************

	//******************************************************************
	//Evaluar los tiempos de ejecución
	//******************************************************************
	//uswtime(&utime1, &stime1, &wtime1);

	//Cálculo del tiempo de ejecución del programa
	/*printf("\n");
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
	printf("\n");*/
	//******************************************************************

	//Terminar programa normalmente
	exit(0);
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES
//************************************************************************
