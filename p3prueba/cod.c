/*
Versión del programa: 1.0

Nombre del programa: Algoritmo de Huffman en lenguaje c (Parte 1 Codificador)

Descripción:
Este programa recibe el archivo a ser comprimido y codificado en un txt
y un archivo de salida en blanco, en el cual sera escrita la codificación,
caundo se termine la codificación dara un mensaje de exito y se pobra ver 
en el archivo de salida la codificación binbaria


Errores:


Equipo: Noobcoders
Fuentes Díaz Jesús Alejandro
García Ledezma Miguel Ángel
García Marciano Edgar
Guadarrama Hidalgo Jorge Luis
Práctica 3
Análisis temporal (algoritmos de búsqueda)
Análisis de algoritmos
Franco Martínez Edgardo Adrián
3CM12

compilación:
gcc codificador.c -o codificador

Ejecución: ./codificador entrada.txt salida.txt
*/

//********Librerias*******
#include <stdio.h>
#include <stdlib.h>
//*************************

//Nodo de árbol, almacena el caracter, las repeticiones, los apuntadores de la rama 0,1 y el apuntador de siguiente
typedef struct nodo
{
    unsigned char letra; //Letra del archivo
    int repeticiones;    //veces que se repie en el archivo
    struct nodo *sig;    //siguiente en la lista
    struct nodo *cero;   //rama izquierda o rama 0
    struct nodo *uno;    //rama derecha o rama 1
} Nodo;

int main(int argc, char *argv[])
{

    return 0;
}