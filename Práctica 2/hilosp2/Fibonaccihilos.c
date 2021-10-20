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
gcc Fiboaccibusquedahiloss.c tiempo.c -o sal -lpthread
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"


int nt; 
int n,j;
int *datos; 
int x[]={322486,14700764,3128036, 6337399, 61396,10393545, 2147445644, 1295390003, 450057883, 187645041,1980098116, 152503, 5000, 1493283650, 214826, 1843349527,1360839354, 2109248666 , 2147470852, 0};

void subarray(int a[],int i,int n,int sa[]){
    int iaux,cont=0;
    for(iaux=i;iaux<i+n;iaux++){
        sa[cont] = a[iaux];
        cont++;
    }
}

void* procesar(void* id) {
    int n_thread=(int)id;
    int inicio,fin,ne;

    inicio=(n_thread*n)/nt;
    if(n_thread==nt-1){ 
        fin=n;
        ne = fin-inicio;
    }
    else{
        fin=((n_thread+1)*n)/nt-1;
        ne = (fin-inicio)+1;
    }

    printf("\nThread %d\tInicio %d\tTermino %d\n",n_thread,inicio,fin);
    
    int *sa = (int*)malloc(ne*sizeof(int));
    subarray(datos,inicio,ne,sa);
    if(fibMonaccianSearch(sa,x[j],ne)!=-1){
        printf("\nNumero %d encontrado %d\n", x[j], id);
    } 
    
    if(n_thread!=0){
        pthread_exit(0); 
    }
      
}

int min(int x, int y) { return (x<=y)? x : y; } 

int fibMonaccianSearch(int arr[], int x, int n) { 
    int fibMMm2 = 0; 
    int fibMMm1 = 1; 
    int fibM = fibMMm2 + fibMMm1; 

    while (fibM < n) { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM = fibMMm2 + fibMMm1; 
    } 

    int offset = -1; 

    while (fibM > 1) { 
        int i = min(offset+fibMMm2, n-1); 

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
        else return i; 
    } 

    if(fibMMm1 && arr[offset+1]==x)return offset+1; 
    return -1; 
} 

int main (int argc, char *argv[]) {   
    int i=0; 
    pthread_t *thread;
    if (argc<2) {
        printf("Indique el nÃºmero de threads - \tEjemplo: [user@equipo]$ %s4\n\n",argv[0]);
        exit(-1);
    }  
    nt=atoi(argv[1]);
    thread = malloc(nt*sizeof(pthread_t));

    if (argc!=3) {
        printf("\nIndique el tamaÃ±o de n - \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
        exit(-1);
    }
    n=atoi(argv[2]);

    datos=(int*)malloc(sizeof(int)*n); 
    
    for(i=0; i<n; i++) {
        scanf("%d", &datos[i]);
    }

    i=0;
printf("\n****Busqueda Fibonacci****\n");
    for(j=0; j<20; j++){

        double utime0=0, stime0=0, wtime0=0, utime1=0, stime1=0, wtime1=0;
printf("Numero a encontrar:%d\n", x[j]);
        uswtime(&utime0, &stime0, &wtime0); 

        for (i=1; i<nt; i++) {    
            if (pthread_create (&thread[i], NULL, procesar,(void*)i) != 0 ) {
                perror("El thread no pudo crearse");
                exit(-1);
            }
        }
        procesar(0);
        
        for (i=1; i<nt; i++){
                pthread_join(thread[i], NULL); 
            }   
        uswtime(&utime1, &stime1, &wtime1); 
        printf("\n");
        printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
        printf("user (Tiempo de procesamiento en CPU's) %.10f s\n", utime1 - utime0);
        printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", nt, (utime1 - utime0) / nt);
        printf("sys (Tiempo en acciónes de E/S)  %.3f s\n", stime1 - stime0);
        printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
        printf("\n");
    } 
    exit (0);   
}

