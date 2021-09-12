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
/*Esta función ordena de forma ascendente un arreglo de numeros enteros
  para ello requiere comparar el elemento n del arreglo con el n-1, 
  comenzando desde la segunda posición del arreglo y de esta forma compara
  si n es menor a n-1 y si es así intercambiará la posición de dichos 
  numeros en el arreglo*/
void insercion(int *A, int n){
	int i, j, temp;
	for (i = 0; i < n; i++)//Recorre todo el arreglo para asegurar que se comparen todos los numeros
	{
		j=i;
		temp=A[i];//Se asigna a temp el valor de la i-esima posición del arreglo
		while((j > 0) && (temp < A[j-1])){/*Se verifica que j sea mayor a 0 y que el valor de la i-esima posición del arreglo (n)
											sea menor a A[j-1] (n-1)*/
			A[j] = A[j-1];/*Se intercambian posiciones, el numero mayor pasa a la j-esima posición*/
			j--;
		}
		A[j] = temp;/*El numero menor se coloca en la j-esima posición ya que previamente j fue decrementado en 1*/
	}
}
/*Esta función ordena de forma ascendente un arreglo de numeros enteros, 
  para ello se basa en buscar el numero más pequeño del arreglo y lo inserta
  en la primera posición del arreglo, despues busca el siguiente numero 
  más pequeño del resto del arreglo y lo pone en la segunda posición del
  arreglo y así sucesivamente hasta terminar de analizar los elementos en
  el arreglo*/
void seleccion(int *A, int n){
	int k, p, i, temp;//Declaración de variables
	for (k = 0; k < n-1; k++)/*Ciclo for que se encargará de que recorramos todo el arreglo hasta su penultima posición,
							   ya que se supone que el elemento de la ultima posición es el mayor y ya está acomodado.*/
	{
		p=k;//la variable p toma el valor de k
		for (i = k+1; i < n; i++)/*Este for se asegura de que recorramos el arreglo desde la i-esima posición hasta n-1, 
								   para encontrar el elemento más pequeño en este subarreglo, cabe destacar que i irá 
								   cambiando y haciendose más grande conforme se van acomodando los numeros en el arreglo*/
		{
			if (A[i] < A[p])// nos ayuda a encontrar el elemento más pequeño del arreglo o subarreglo según sea el caso
			{
				p=i;// la variable p toma el valor de i
			}
		}
		temp = A[p];//Le asignamos a la variable temp el valor en la p-esima posición del arreglo A
		A[p] = A[k];//A la p-esima posición del arreglo A le asignamos la K-esima posición del arreglo A
		A[k] = temp;//A la k-esima posición del arreglo A le asignamos el contenido de temp
	}
}





//Importante
//
//
//Al llamar a la funcines se relaiza de la forma: NombreFuncion(A, 0, n-1);
//
//
//

/*
Método de ordenamiento por mezcla:
La función recibe como argumentos dos enteros los cuales son la 
referencia del inicio (p) y el final(r) del arreglo y también recibe 
el apuntador a el arreglo. Con el uso de recursión la función divide 
el arreglo en sub-arreglos hasta obtener arreglos de un entero de largo.
Una vez obtenido este sub-arreglo se retorna y se comienza a ordenar 
mediante la llamada a la función Merge la cual ordena cada sub-arreglo 
obtenido.
*/
void MergeSort(int *A, int p, int r){ 
	int q;                            //Permite dividir el arregloen sub arreglos de aproximadamente la mitad de largo
	if(p < r){ 
		q = (int)((float)(p+r)/2);
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		Merge(A, p, q, r);
	}
	return;
}
void Merge(int *A, int p, int q, int r){
	int l = r-p+1;                      //largo del sub-arreglo
	int i = p;							//inicio del sub-arreglo
	int j = q+1;						//mitad del sub arreglo 
	int k;								//Variable para los bucles
	int C[r-p+1];						//Sub-arreglo para cambiar posiciones
	for(k=0;k<l;k++){
		if(i<=q && j<=r){
			if(A[i]<A[j]){
				C[k]=A[i];
				i++;
			}else{
				C[k]=A[j];
				j++;
			}
		}else if(i<=q){
			C[k]=A[i];
			i++;
		}else{
			C[k]=A[j];
			j++;
		}
	}
	for(k=0;k<l;k++){
		A[p+k]=C[k];
	}
}



/*
Método de ordenamiento rápido:
El método consta de 3 funciones QuickSort la cual recibe 3 argumentos
el apuntador al arreglo, y los indicadores de inicio y fin del arreglo. 
Esta función se encarga de dividir el arreglo con el uso de recursion 
en sub-arreglos y poder ordenar los elementos del arreglo. 
Pivot la cual se encarga de retornar el subíndice del elemento del 
arreglo que se usara como pivote, recibe los mismos argumentos que 
QuickSort.
Intercambiar la cual como su nombre lo indica se encarga de intercambiar 
la posición de dos elementos del arreglo entre si. Recibe los subíndices 
de los elementos del arreglo y el apuntador al arreglo.

*/
void QuickSort(int *A,int p,int r){
	int j;								//Se usara para alamcenar el subidice del pivote
	if(p<r){
		j=Pivot(A,p,r);
		QuickSort(A, p, j);
		QuickSort(A, j+1, r);
	}
	return;
}
int Pivot(int *A,int p,int r){
	int piv;					//almacenara el pivote
	int i;						//subidice del inicio del sub-arreglo
	int j;						//subidice del final del sub-arreglo
	piv=A[p];
	i=p;
	j=r;
	while(1){
		while(A[i]<piv)			//verifica que los elementos del inicio sean menores que el pivote
			i++;
		while(A[j]>piv)			//verifica que los elementos del final sean mayores que el pivote
			j--;
		if(i>=j){				//retorna el pivote
			return j;
		}else{					//intercambia posiciones de elemntos del sub-arreglo
			Intercambiar(A, i, j);
			i++;
			j--;
		}
	}
	
	
}
void Intercambiar(int *A, int i, int j){
	int temp;
	temp=A[j];
	A[j]=A[i];
	A[i]=temp;
}