/*
Versión del programa: 3.0

Nombre del programa: Algoritmo de Huffman en lenguaje c (Parte 2 Decodificador)

Descripción:
Este programa recibe el archivo de salida codificado.dat y el archivo de entrada.txt
posteriormente realiza la descompresion al leer el número de elementos y la longitud
y construyendo el arbol nuevamente. Cuando termine de decodificar nos devolvera el 
archivo decodificado.txt y un archivo de porcentaje de compresión.txt, en el cual se 
recuperan los datos de los archivos y se calcula el porcentaje de descomprecion.


Errores:
En ocaciones no comprime, expande.


Equipo: Noobcoders
Fuentes Díaz Jesús Alejandro
García Ledezma Miguel Ángel
García Marciano Edgar
Guadarrama Hidalgo Jorge Luis
Práctica 3
Algoritmo de huffman
Análisis de algoritmos
Franco Martínez Edgardo Adrián
3CM12

++++++++++++++++++++++++++++++++++++++++++++Versiones anteirores y enlaces+++++++++++++++++
(C) Noviembre de 2000 Salvador Pozo Coronado           
(C) Noviembre de 2018-2021 Mariano Ruiz (correcciones) 
https://www.delftstack.com/es/howto/c/file-size-in-c/

Ejecución y compilación desde script:
gcc decompres.c -o decompres
time(./decompres codificado.dat entrada.txt) > porcentaje_de_comprecion.txt
*/

 


//Librerias
#include <stdio.h>
#include <stdlib.h>
//librerias para el calculo de compresión
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>

/* Tipo nodo para árbol */
typedef struct _nodo
{
   unsigned char letra;    /* Letra a la que hace referencia el nodo */
   unsigned long int bits; /* Valor de la codificación de la letra */
   char nbits;             /* Número de bits de la codificación */
   struct _nodo *cero;     /* Puntero a la rama cero de un árbol */
   struct _nodo *uno;      /* Puntero a la rama uno de un árbol */
} tipoNodo;                /* Nombre del tipo */

/* Funciones prototipo */
void BorrarArbol(tipoNodo *n);

int main(int argc, char *argv[])
{
   tipoNodo *Arbol;        /* Arbol de codificación */
   long int Longitud;      /* Longitud de fichero */
   int nElementos;         /* Elementos de árbol */
   unsigned long int bits; /* Almacen de bits para decodificación */
   FILE *fe, *fs;          /* Ficheros de entrada y salida */

   struct stat sb1, sb2; //Estructura para medir la compresion

   tipoNodo *p, *q; /* Auxiliares */
   unsigned char a;
   int i, j;

   if (argc < 4)
   {
      printf("Usar:\n%s <fichero_entrada> <Fichero_original> <Fichero_de_salida>\n", argv[0]);
      return 1;
   }

   /* Crear un arbol con la información de la tabla */
   Arbol = (tipoNodo *)malloc(sizeof(tipoNodo)); /* un nodo nuevo */
   Arbol->letra = 0;
   Arbol->uno = Arbol->cero = NULL;
   fe = fopen(argv[1], "rb");
   fread(&Longitud, sizeof(long int), 1, fe); /* Lee el número de caracteres */
   fread(&nElementos, sizeof(int), 1, fe);    /* Lee el número de elementos */
   for (i = 0; i < nElementos; i++)           /* Leer todos los elementos */
   {
      p = (tipoNodo *)malloc(sizeof(tipoNodo));          /* un nodo nuevo */
      fread(&p->letra, sizeof(char), 1, fe);             /* Lee el carácter */
      fread(&p->bits, sizeof(unsigned long int), 1, fe); /* Lee el código */
      fread(&p->nbits, sizeof(char), 1, fe);             /* Lee la longitud */
      p->cero = p->uno = NULL;
      /* Insertar el nodo en su lugar */
      j = 1 << (p->nbits - 1);
      q = Arbol;
      while (j > 1)
      {
         if (p->bits & j) /* es un uno*/
            if (q->uno)
               q = q->uno; /* Si el nodo existe, nos movemos a él */
            else           /* Si no existe, lo creamos */
            {
               q->uno = (tipoNodo *)malloc(sizeof(tipoNodo)); /* un nodo nuevo */
               q = q->uno;
               q->letra = 0;
               q->uno = q->cero = NULL;
            }
         else /* es un cero */
             if (q->cero)
            q = q->cero; /* Si el nodo existe, nos movemos a él */
         else            /* Si no existe, lo creamos */
         {
            q->cero = (tipoNodo *)malloc(sizeof(tipoNodo)); /* un nodo nuevo */
            q = q->cero;
            q->letra = 0;
            q->uno = q->cero = NULL;
         }
         j >>= 1; /* Siguiente bit */
      }
      /* Ultimo Bit */
      if (p->bits & 1) /* es un uno*/
         q->uno = p;
      else /* es un cero */
         q->cero = p;
   }
   /* Leer datos comprimidos y extraer al fichero de salida */
   bits = 0;
   fs = fopen(argv[3], "w");
   /* Lee los primeros cuatro bytes en la dobel palabra bits */
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
   j = 0; /* Cada 8 bits leemos otro byte */
   q = Arbol;
   /* Bucle */
   do
   {
      if (bits & 0x80000000)
         q = q->uno;
      else
         q = q->cero; /* Rama adecuada */
      bits <<= 1;     /* Siguiente bit */
      j++;
      if (8 == j) /* Cada 8 bits */
      {
         i = fread(&a, sizeof(char), 1, fe); /* Leemos un byte desde el fichero */
         bits |= a;                          /* Y lo insertamos en bits */
         j = 0;                              /* No quedan huecos */
      }
      if (!q->uno && !q->cero) /* Si el nodo es una letra */
      {
         putc(q->letra, fs); /* La escribimos en el fich de salida */
         Longitud--;         /* Actualizamos longitud que queda */
         q = Arbol;          /* Volvemos a la raiz del árbol */
      }
   } while (Longitud); /* Hasta que acabe el fichero */
   /* Procesar la cola */

   fclose(fs); /* Cerramos ficheros */
   fclose(fe);

   BorrarArbol(Arbol); /* Borramos el árbol */

   //MEDICION DE COMPRECIÓN

   /*
   Obtenemos los datos del archivo .dat y el .txt original y tilizamos la funcion stat en
   lenguaje c.
   */

   printf("Archivo comprimido %s\n", argv[1]);

   if (stat(argv[1], &sb1) == -1) //llamamos a stat, le pasamos el nombre del archivo y la estructra stat
   {
      perror("stat");
      exit(EXIT_FAILURE); //Si no se pueden obtener los datos el programa termina
   }
   //impreción de los datos obtenidos del archivo.
   printf("Inode number: %lu\n", sb1.st_ino);
   printf("User ID of owner: %u\n", sb1.st_uid);
   printf("Group ID of owner: %u\n", sb1.st_gid);
   printf("Total file size: %lu bytes\n", sb1.st_size);
   printf("Last status change:       %s", ctime(&sb1.st_ctime));
   printf("Last file access:         %s", ctime(&sb1.st_atime));
   printf("Last file modification:   %s", ctime(&sb1.st_mtime));

   printf("\n");

   printf("Archivo Sin comprimir %s\n", argv[2]);

   if (stat(argv[2], &sb2) == -1)//llamamos a stat, le pasamos el nombre del archivo y la estructra stat
   {
      perror("stat");
      exit(EXIT_FAILURE);//Si no se pueden obtener los datos el programa termina
   }
   //impreción de los datos obtenidos del archivo.
   printf("Inode number: %lu\n", sb2.st_ino);
   printf("User ID of owner: %u\n", sb2.st_uid);
   printf("Group ID of owner: %u\n", sb2.st_gid);
   printf("Total file size: %lu bytes\n", sb2.st_size);
   printf("Last status change:       %s", ctime(&sb2.st_ctime));
   printf("Last file access:         %s", ctime(&sb2.st_atime));
   printf("Last file modification:   %s", ctime(&sb2.st_mtime));

   printf("\n");
   printf("\n");
   //imprecion de porcentaje de compresion mediante regla de tres.
   printf("Porcentaje de descomprecion = (%lu x 100) /%lu = %lu porciento\n", sb1.st_size, sb2.st_size, (sb1.st_size * 100) / sb2.st_size);
   if((sb1.st_size * 100) / sb2.st_size>100)
   printf("E programa no comprimio: %lu porciento\n",((sb1.st_size * 100) / sb2.st_size)-100);
   else
   printf("El programa comprimio: %lu porciento\n",100-((sb1.st_size * 100) / sb2.st_size));
   return 0;
}

/* Función recursiva para borrar un arbol */
void BorrarArbol(tipoNodo *n)
{
   if (n->cero)
      BorrarArbol(n->cero);
   if (n->uno)
      BorrarArbol(n->uno);
   free(n);
}
