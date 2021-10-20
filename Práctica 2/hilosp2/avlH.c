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
gcc avlH.c tiempo.c -o sal -lpthread
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//Estructuras
//*****************************************************************
typedef struct nodo{
	int dato;								//dato del nodo
	int altura;								//Indica de que lado esta cargado el nodo
	struct nodo *hijoIzquierdo;						//apuntador hijo izquierdo
	struct nodo *hijoDerecho;						//"  "   "  "   " derecho
}Nodo;
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int NumThreads; //Número de threads
int N, j;       // N es el tamaño del problema, j es un iterador auxiliar
int *A;         //Arreglo del archivo
Nodo *r = NULL;				//Creacion del arbol
//Areglo de búsqueda
int B[] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 1295390003, 450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666, 2147470852, 0};



//********************************************************************************
//DECLARACION DE FUNCIONES

void *procesar(void *id)
{
	int dato = *((int *)id);
    if(buscar(r,dato)){
		printf("Se encontro el dato %d\n",dato);
	}else{
		printf("No se encontro el dato %d\n",dato);
	}
}



int altura(Nodo *r){
	if(r == NULL) 
		return	-1;
	else 
		return r->altura;
}

int max(int a,int b){
	return a > b ? a : b;
}

Nodo *rotacion_der(Nodo *r){
	Nodo *temp;
	temp = r->hijoDerecho;
	r->hijoDerecho=temp->hijoIzquierdo;
	temp->hijoIzquierdo = r;
	r->altura = max(altura(r->hijoIzquierdo), altura(r->hijoDerecho))+1;
	temp->altura = max(altura(temp->hijoDerecho), r->altura) + 1;
	return temp;
}

Nodo *rotacion_izq(Nodo *r){
	Nodo *temp;
	temp = r->hijoIzquierdo;
	r->hijoIzquierdo = temp->hijoDerecho;
	temp->hijoDerecho = r;
	r->altura = max (altura(r->hijoDerecho), altura(r->hijoIzquierdo)) + 1;
	temp->altura = max(altura(temp->hijoIzquierdo), r->altura) + 1;
	return temp;
}

Nodo *rot_doble_izq(Nodo *r){
	r->hijoIzquierdo = rotacion_der(r->hijoIzquierdo);
	return rotacion_izq(r);
}

Nodo *rot_doble_der(Nodo *r){
	r->hijoDerecho = rotacion_izq(r->hijoDerecho);
	return rotacion_der(r);
}

Nodo *nuevo(){
	Nodo *temp=(Nodo *) malloc(sizeof(Nodo));
	if (temp == NULL){
			exit(0);
		}
	return temp;
}

Nodo *insertar(int dato, Nodo *r){
	if(r == NULL){
	r = nuevo();
	r->dato = dato;
	r->altura = 0;
	r->hijoDerecho = NULL;
	r->hijoIzquierdo= NULL;
	}
	else if(dato < r->dato){
		r->hijoIzquierdo = insertar (dato, r->hijoIzquierdo);
		if(altura(r->hijoIzquierdo) - altura(r->hijoDerecho) == 2)
		if(dato < r->hijoIzquierdo->dato)
			r=rotacion_izq(r);
		else
			r=rot_doble_izq(r);
	}
	else if(dato > r->dato){
		r->hijoDerecho = insertar (dato, r->hijoDerecho);
		if(altura(r->hijoDerecho) - altura(r->hijoIzquierdo) == 2)
		if(dato > r->hijoDerecho->dato)
			r=rotacion_der(r);
		else
			r=rot_doble_der(r);
	}
	else{
		return r;											//En caso de que un valor se repita
	}
		
	r->altura = max(altura(r->hijoIzquierdo), altura(r->hijoDerecho))+1;
	return r;
}

void imprimir(Nodo *r,int cont){							// funcion imprimir en consola, para pruebas con n�s peque�as
	int i;
	if(r == NULL)
		return ;
	else{
		imprimir(r->hijoDerecho,cont+1);
		for(i=0;i<cont;i++)
			printf("   ");
		printf("%d\n",r->dato);
		imprimir(r->hijoIzquierdo,cont+1);
	}
}

int alturaarbol(Nodo *r){									//Retorna la altura del arbol
	int izq;
	int der;
	if(r==NULL)
		return 0;
	izq=altura(r->hijoIzquierdo)+1;
	der=altura(r->hijoDerecho)+1;
	if(izq>der)
		return izq;
	else if(izq<der)
		return der;
	else 
		return der;
}

int buscar(Nodo *r, int dato){
	Nodo *temp = r;
	while(r!=NULL){
		if(dato < r->dato){
			r=r->hijoIzquierdo;
		}else if(dato > r->dato){
			r=r->hijoDerecho;
		}else{
			return 1;
		}
	}
	return 0;
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
    pthread_t thread;
	//Si no se introducen exactamente 3 argumentos (Cadena de ejecución , Número de hilos ,cadena=n)///////////////////////////////////
    if (argc != 2)
    {
        printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100 \n", argv[0]);
        exit(1);
    }
    //Tomar el segundo como tamaño n
	N = atoi(argv[1]);//////////////////////////////////////////////////////////////////////////////////////
    // Lectura del archivo 10millones(ord-des).txt mediante redireccionamiento.
	int entrada_arbol;//Variable auxiliar para leer los datos del archivo y insertarlos en el arbol
    for (i = 0; i < 11; i++)//Lectura del archivo y acomodo en el arbol
    {
        scanf("%d", &entrada_arbol);
        r = insertar(entrada_arbol,r);
    }
    //*******************************************************************************************************

    //ciclo  para la búsqueda de cada número
    printf("\n****Busqueda Arbol AVL****\n");
    for (j = 0; j < 20; j++)
    {
        printf("Numero a encontrar:%d\n", B[j]);
        uswtime(&utime0, &stime0, &wtime0); //inicio del conteo de tiempo

        //Crear los threads con la función "procesar" que realiza la búsqueda lineal
        pthread_create(&thread, NULL, procesar, &B[j]);
    


        pthread_join(thread, NULL); //Espera a los hilos
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
