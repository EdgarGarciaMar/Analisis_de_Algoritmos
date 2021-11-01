/*
Versión del programa: 1.0

Nombre del programa: Algoritmo de Huffman en lenguaje c

Descripción:
Este programa recibe el archivo a ser comprimido y codificado en un txt
y cuando el programa termian da un archivo  con la codificación


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
*/

//********Librerias*******
#include <stdio.h>
#include <stdlib.h>
//*************************

//***********Estructuras******************************************

//Nodo de árbol, almacena el caracter, las repeticiones, los apuntadores de la rama 0,1 y el apuntador de siguiente
typedef struct nodo
{
    unsigned char letra; //Letra del archivo
    int repeticiones;    //veces que se repie en el archivo
    struct nodo *sig;    //siguiente en la lista
    struct nodo *cero;   //rama izquierda o rama 0
    struct nodo *uno;    //rama derecha o rama 1
} Nodo;

//Estructura de un nodo de lista, para tener los subarboles ordenados, almacena la letra, los bits
typedef struct lista
{
    unsigned char letra;          //letra del archivo
    unsigned long int bits;       //bits de la codificación
    unsigned char numero_de_bits; //número de bits de la codificación
    struct lista *sig;            //siguiente de la lista
} Lista_letras;

Lista_letras *Tabla;
//*************************************Funciones**************************************************

//función que identifica los caracteres y los cuenta, recibe el caracter escaneado en main y un apuntador a la lista, de modo
//que cuando se compruebe la referencia se sabra si esta vacia la lista, o si tiene elementos.
void contar(Nodo **lista, unsigned char c)
{
    Nodo *auxLista, *auxa, *auxb; //Nodos auxiliares;

    if (!*lista) // verifica si la lista esta vacia, si lo esta crea un nodo
    {
        *lista = (Nodo *)malloc(sizeof(Nodo));                 //memoria de nuevo nodo
        (*lista)->letra = c;                                   //caracter leido en main
        (*lista)->repeticiones = 1;                            //número de repeticiones del caracter
        (*lista)->sig = (*lista)->cero = (*lista)->uno = NULL; //Se ponen las ramas a null porque es el primer nodo
    }
    else
    { //si no esta vacia se busca el caracter recorriendo la lista
        auxLista = *lista;
        auxa = NULL;
        while (auxLista && auxLista->letra < c)
        {
            auxa = auxLista;
            auxLista = auxLista->sig; //Guardamos el elemente y sgeuimos recorriendo
        }

        if (auxLista && auxLista->letra == c)
        {
            auxLista->repeticiones++; //comprobación de si el arbol no esta vacio y el noto contiene la letra escaneada en main aumentamos la repetición
        }
        else
        {
            auxLista = (Nodo *)malloc(sizeof(Nodo)); //memoria para el nuevo nodo
            auxb->letra = c;                         //se guarda el caracter escaneado
            auxb->repeticiones = 1;                  //se guarda la repetición
            auxb->cero = auxLista->uno = NULL;       //se ponen sus ramas a null
            auxb->sig = auxLista;
            if (auxa) //se inserta entre los nodos
            {
                auxa->sig = auxLista; //de la lista
            }
            else
            {
                *lista = auxLista; //si el aux es null, el aux se vuelve el primero
            }
        }
    }
}

//inserta el elemento aux en la lista ordenada por el número de repeticiones, recibe el puntero de la raiz u el elemento aux
void insertarRaiz(Nodo **raiz, Nodo *aux)
{
    Nodo *auxlista, *auxa;
    if (!*raiz) //si la raiz es null, es el primer elemento
    {
        *raiz = aux;
        (*raiz)->sig = NULL;
    }
    else
    {
        //si no esta vacia obuscamos el caractes en la lista
        auxlista = *raiz;
        auxa = NULL;
        while (auxlista && auxlista->repeticiones < aux->repeticiones)
        {
            auxa = auxlista;          //guardamos el elemento
            auxlista = auxlista->sig; // continuamos el recorrido
        }
        //insercion del elemento
        aux->sig = auxlista;
        if (auxa)
        {
            auxa->sig = aux; //insertar entre auxa y auxlista
        }
        else
        {
            *raiz = aux; //el nuevo elemento es el primero
        }
    }
}

//Ordena la lista de las menores repeticiones a las mayores, recibe la lista
void ordenar(Nodo **lista)
{
    Nodo *lista2, *auxa;
    if (!*lista) //comprueba si la lista esta vacia
    {
        printf("lista vacia en ordenar\n");
        return;
    }
    lista2 = *lista;
    *lista = NULL;
    while (lista2)
    {
        auxa = lista2;
        lista2 = auxa->sig;
        insertarRaiz(lista, auxa);
    }
}

//función de borras árbol recibe el nodo del árbol para ser borrado
void Borrar(Nodo *n)
{
    if (n->cero)
        Borrar(n->cero); //recorrido por rama izquierda
    if (n->uno)
        Borrar(n->uno); //recorrido por rama derecha
    free(n);
}

//Insertar un elemrnto en la tabla
void insertTable(unsigned char c, int lon, int val)
{
    Lista_letras *t, *p, *a;
    t = (Lista_letras *)malloc(sizeof(Lista_letras)); //Crea un elemento tipo tabla
    t->letra = c;                                     //Se inicializan los elementos de la tabla
    t->bits = val;
    t->numero_de_bits = lon;

    if (!Tabla) //Si tabla es NULL, t será el primer elemento
    {
        Tabla = t;
        Tabla->sig = NULL;
    }
    else
    {
        //Se busca el caracter en la lista (ordenada por frecuencia)
        p = Tabla;
        a = NULL;
        while (p && p->letra < t->letra)
        {
            a = p;      //Guardamos el elemento actual para ser insertado
            p = p->sig; //Avanzamos al siguiente elemnto
        }
        //Insertamos el elemento
        t->sig = p;
        if (a)
            a->sig = t; //Insertamos el elemento entre a y p
        else
            Tabla = t; //El nuevo elemento será el rpimero
    }
}
//Función recursiva que nos ayuda a crear la tabla
/*Su trabajo es recorrer el arbol cuya raiz es n
y le asigna el codigo val de lon bites*/
void createTable(Nodo *n, int lon, int val)
{
    if (n->uno)
        createTable(n->uno, lon + 1, (val << 1) | 1);
    if (n->cero)
        createTable(n->cero, lon + 1, val << 1);
    if (!n->uno && !n->cero)
        insertTable(n->letra, lon, val);
}

/*Nos ayuda a encontrar un caracter en la tabla, 
 nos devuelve un apuntador al elemento de la tabla en el que se encuentra el char*/
Lista_letras *searchChar(Lista_letras *Tabla, unsigned char c)
{
    Lista_letras *tab;

    tab = Tabla;
    while (tab && tab->letra != c)
        tab = tab->sig;
    return tab;
}

//********************************Main*****************************************************

int main(int argc, char *argv[])
{
    Nodo *arbol; //árbol de letra y frecuencias
    Nodo *lista; //lista de letras

    Nodo *auxNodo;          //variables auxiliares
    Lista_letras *auxLista; //variables auxiliares

    FILE *fe, *fs;     //ficheros de entrada y salida
    unsigned char aux; //variables auxiliares

    int numeroElementos;       //elementos de la lista
    long int longitud = 0;     //longitud del fichero sin comprimir
    int numeroBits;            //número de bits utilizados
    unsigned long int Codword; //palabra usada dentro de la codificación

    printf("*****Algoritmo de Huffman***\n");
    printf("--Codificador--\n");

    if (argc < 2) //3
    {
        printf("\n %s Archivo_de_entrada.txt Archivo_de_salida.txt", argv[0]);
        exit(1);
    }

    lista = NULL;
    //*********fase 1 contar las frecuencias de todas las letras******************

    fe = fopen(argv[1], "r");
    while (1)
    {
        aux = fgetc(fe);
        if (feof(fe)) //deviuelve si llego al final del archivo
        {
            break;
        }
        longitud++;          //Actualiza la cuenta del fichero
        contar(&lista, aux); //Cuenta y actualiza la lista  de las repeticiones por caracter
    }
    fclose(fe);
    //******ordenamiento de la lista en orden acendente*****
    ordenar(&lista);

    //******Árbol****************
    arbol = lista;
    while (arbol && arbol->sig)
    {
        auxNodo = (Nodo *)malloc(sizeof(Nodo));                                           //memoria del nuevo nodo
        auxNodo->letra = 0;                                                               //se indica que no corresponde a ninguna letra, porque se esta construyendo el árbol
        auxNodo->uno = arbol;                                                             //inserta en la rama 1 el nodo del arbol
        arbol = arbol->sig;                                                               //pasa al siguiente nodo del arbol
        auxNodo->cero = arbol;                                                            //inserta el segundo nodo del arbol en la rama 0
        arbol = arbol->sig;                                                               //se vuelve a recorrer
        auxNodo->repeticiones = auxNodo->uno->repeticiones + auxNodo->cero->repeticiones; //se suman las repeticiones del árbol
        insertarRaiz(&arbol, auxNodo);                                                    //Se termina de hacer el árbol con los caracteres y de forma ordenada acorde las repeticiones
    }

    //*******tabla de los códigos binarios************
    Tabla = NULL;
    createTable(arbol, 0, 0); //Creamos el arbol

    //*************Creación de un fichero de salida**************************************
    fs = fopen(argv[2], "wb");
    //Longitud del fichero
    fwrite(&longitud, sizeof(long int), 1, fs);
    numeroElementos = 0; //Conteo de números en la tabla
    auxLista = Tabla;
    while (auxLista)
    {
        numeroElementos++;
        auxLista = auxLista->sig;
    }
    //Escritura de el los elementos de la tabla
    fwrite(&numeroElementos, sizeof(int), 1, fs);
    //Escribir la tabla en el fichero
    auxLista = Tabla;
    while (auxLista)
    {
        fwrite(&auxLista->letra, sizeof(char), 1, fs);
        fwrite(&auxLista->bits, sizeof(unsigned long int), 1, fs);
        fwrite(&auxLista->numero_de_bits, sizeof(char), 1, fs);
        auxLista = auxLista->sig;
    }

    //Codificacion del fichero de entrada
    fe = fopen(argv[1], "r");
    Codword = 0;
    numeroBits = 0; //ningun bit
    do
    {
        aux = fgetc(fe);
        if (feof(fe)) //deviuelve si llego al final del archivo
        {
            break;
        }

        //Buscamos en la tabla
        auxLista = searchChar(Tabla, aux);
        while (numeroBits + auxLista->bits > 32) //si numeroBits + auxLista->bits > 32 saca un byte
        {
            aux = Codword >> (numeroBits - 8); //Extrae los 8 bits de mayor peso
            fwrite(&aux, sizeof(char), 1, fs); //Lo escribe en el fichero
            numeroBits -= 8;
        }
        Codword <<= auxLista->numero_de_bits;   //Espacio para el nuevo caracter
        Codword |= auxLista->bits;              //Se agrega el nuevo caracter
        numeroBits += auxLista->numero_de_bits; //Se actualiza la cuenta de bits

    } while (1);

    while (numeroBits > 0)
    {
        if (numeroBits >= 8)
            aux = Codword >> (numeroBits - 8);
        else
            aux = Codword << (8 - numeroBits);
        fwrite(&aux, sizeof(char), 1, fs);
        numeroBits -= 8;
    }

    fclose(fe);
    fclose(fs);

    Borrar(arbol);

    while (Tabla)
    {
        auxLista = Tabla;
        Tabla = auxLista->sig;
        free(auxLista);
    }

    return 0;
}