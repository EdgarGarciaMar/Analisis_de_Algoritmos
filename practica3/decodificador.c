/*
Versión del programa: 1.0

Nombre del programa: Algoritmo de Huffman en lenguaje c (Parte 2 Decodificador)

Descripción:
Este programa recibe el archivo de salida de la parte 1 de este programa y un archivo
en balnco que sera el archivo decodificado porque en ese archivo se escribira el mensaje 
en español.


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
gcc decodificador.c -o decodificador

Ejecución: ./decodificador salida.txt decodificado.txt
*/

#include <stdlib.h>
#include <stdio.h>
//int Longitud;
/*Estructuras*/
typedef struct _nodo
{
    unsigned char letra;
    unsigned long int bits;
    char nbits;
    struct _nodo *cero;
    struct _nodo *uno;
} tipoNodo;

//función de borras árbol recibe el nodo del árbol para ser borrado
void Borrar(tipoNodo *n)
{
    if (n->cero)
        Borrar(n->cero); //recorrido por rama izquierda
    if (n->uno)
        Borrar(n->uno); //recorrido por rama derecha
    free(n);
}

int main(int argc, char *argv[])
{
    tipoNodo *Arbol;        //Arbol de codificacion
    long int Longitud;      //Longitud de fichero
    long int nElementos;    //número de elementos
    unsigned long int bits; //Elementos de arbol
    FILE *fe, *fs;          //Ficheros de entrada y salida
    tipoNodo *p, *q;        //Auxiliares
    unsigned char a;
    int i, j;

    if (argc != 3)
    {
        printf("Usar: \n%s ArchivoEntrada.txt ArchivoSalida.txt\n", argv[0]);
        //return 1;
        exit(1);
    }

    /*crear un arbol con la tabla*/
    Arbol = (tipoNodo *)malloc(sizeof(tipoNodo)); //un nodo nuevo
    Arbol->letra = 0;
    Arbol->uno = Arbol->cero = NULL;
    fe = fopen(argv[1], "rb");
    fread(&Longitud, sizeof(long int), 1, fe); //lee el numero de caracteres
    fread(&nElementos, sizeof(int), 1, fe);    //lee el numero de elementod
    printf("Lei los datos : %ld ,%ld\n", Longitud, nElementos);
    for (i = 0; i < nElementos; i++)
    {                                                      //leer todos los elementos
        p = (tipoNodo *)malloc(sizeof(tipoNodo));          //un nuevo nodo
        fread(&p->letra, sizeof(char), 1, fe);             //lee el caracter
        fread(&p->bits, sizeof(unsigned long int), 1, fe); //lee el codigo
        fread(&p->nbits, sizeof(char), 1, fe);             //lee ka longitud
        p->cero = p->uno = NULL;
        /*insertar el nodo en su lugar*/
        j = 1 << (p->nbits - 1);
        q = Arbol;
        printf("for\n");
        while (j > 1)
        {
            if (p->bits & j) //es un uno
                if (q->uno)
                    q = q->uno;
                else
                {                                                  //si no existe se crea
                    q->uno = (tipoNodo *)malloc(sizeof(tipoNodo)); //un nodo nuevo
                    q = q->uno;
                    q->letra = 0;
                    q->uno = q->cero = NULL;
                }

            else //es un cero
                if (q->cero)
                q = q->cero;
            else
            {
                q->cero = (tipoNodo *)malloc(sizeof(tipoNodo)); //un nodo nuevo
                q = q->cero;
                q->letra = 0;
                q->uno = q->cero = NULL;
            }
            j >>= 1; //siguiente bit
            printf("while\n");
        }
        /*ultimo bit*/
        if (p->bits & 1)
        {
            q->uno = p; //es un uno
        }
        else
        {
            q->cero = p; //es un cero
        }
    }
    printf("leerdatos\n");
    /*Leer datos comprimidos y extrar al fichero de salida*/
    bits = 0;
    fs = fopen(argv[2], "w");
    /*Lee los primeros cuatro bytesen la dobel palabra bits*/
    fread(&a, sizeof(char), 1, fe);
    bits |= a;
    bits <<= 8;
    fread(&a, sizeof(char), 1, fe);
    bits |= a;
    bits <<= 8;
    fread(&a, sizeof(char), 1, fe);
    bits |= a;
    bits <<= 8;
    fread(&a, sizeof(char), 1, fe);
    bits |= a;
    bits <<= 8;
    j = 0; /*cada 8 bits leemos otro byte*/
    q = Arbol;
    /*Bucle*/
    do
    {
        if (bits & 0x80000000)
        {
            q = q->uno;
        }
        else
        {
            q = q->cero; /*Rama adecuada*/
        }
        bits <<= 1;
        j++;
        if (8 == j)
        {                                       /*Cada 8 bits*/
            i = fread(&a, sizeof(char), 1, fe); //leemos un byte desde el fichero
            bits |= a;                          //y lo insertamos en bits
            j = 0;                              //no quedan huecos
        }
        if (!q->uno && !q->cero)
        {
            putc(q->letra, fs); //la escribimos en el fichero de salida
            Longitud--;         //actulizamos la longitud que queda
            q = Arbol;          //volvemos a la raiz del arbol
        }
    } while (Longitud);
    /*procesar la cola*/
    fclose(fs); //Cerramos ficheros
    fclose(fe);
    Borrar(Arbol); //Borramos el arbol
    return 0;
}
