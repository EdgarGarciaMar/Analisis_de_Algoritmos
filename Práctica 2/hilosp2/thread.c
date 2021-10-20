#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

struct args_thread
{
    int *arr;
    int l, r, x, th_n;
};

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
	    printf("El elemento se encuentra en el hilo %d\n", argumentos->th_n);
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


int main(int argc, char const *argv[])
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int tamano_arr = sizeof(arr) / sizeof(arr[0]);
    int n_hilos = (int)(log(sizeof(arr)/4.00) / log(2));
    pthread_t hilos[n_hilos];
    int x = 40, modulo, fact_comun;
    struct args_thread argumentos;
    argumentos.arr = arr;
    argumentos.x = x;
    modulo = tamano_arr % n_hilos;
    fact_comun = tamano_arr / n_hilos;

	//printf("numero de hilos %d, tamano arr = %d\n", n_hilos, tamano_arr);
	//printf("valor del log %f\n", log(sizeof(arr)/4.00));

    for (int i = 0; i < n_hilos; i++)
    {
        //pthread_t hiloBaby;
        //hilos[i] = hiloBaby; 
        argumentos.l = fact_comun*i;
        argumentos.th_n = i;
        if (modulo == 0)
        {
            argumentos.r = fact_comun*(i + 1) - 1;
        }else{
            argumentos.r = fact_comun*(i + 1) - 1 + modulo;
        }
        pthread_create(&hilos[i], NULL, &busquedaBinaria, (void *)&argumentos);
	printf("Soy el hilo %d\n", i);
        pthread_join(hilos[i], NULL);        
    }
    

        
    return 0;
}
