/* Compresión de archivos usando el Algoritmo de Huffman: */
/* (C) Noviembre de 2000 Salvador Pozo Coronado           */
/* (C) Noviembre de 2018-2021 Mariano Ruiz (correcciones) */
/* Descompresor */

#include <stdio.h>
#include <stdlib.h>
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

   if (argc < 3)
   {
      printf("Usar:\n%s <fichero_entrada> <Fichero_original> \n", argv[0]);
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
   fs = fopen("decodificado.txt", "w");
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

   printf("Archivo comprimido %s\n", argv[1]);

   if (stat(argv[1], &sb1) == -1)
   {
      perror("stat");
      exit(EXIT_FAILURE);
   }

   printf("Inode number: %lu\n", sb1.st_ino);
   printf("User ID of owner: %u\n", sb1.st_uid);
   printf("Group ID of owner: %u\n", sb1.st_gid);
   printf("Total file size: %lu bytes\n", sb1.st_size);
   printf("Last status change:       %s", ctime(&sb1.st_ctime));
   printf("Last file access:         %s", ctime(&sb1.st_atime));
   printf("Last file modification:   %s", ctime(&sb1.st_mtime));

   printf("\n");

   printf("Archivo Sin comprimir %s\n", argv[2]);

   if (stat(argv[2], &sb2) == -1)
   {
      perror("stat");
      exit(EXIT_FAILURE);
   }

   printf("Inode number: %lu\n", sb2.st_ino);
   printf("User ID of owner: %u\n", sb2.st_uid);
   printf("Group ID of owner: %u\n", sb2.st_gid);
   printf("Total file size: %lu bytes\n", sb2.st_size);
   printf("Last status change:       %s", ctime(&sb2.st_ctime));
   printf("Last file access:         %s", ctime(&sb2.st_atime));
   printf("Last file modification:   %s", ctime(&sb2.st_mtime));

   printf("\n");
   printf("\n");

   printf("Porcentaje de descomprecion = (%lu x 100) /%lu = %lu porciento de comprecion", sb2.st_size, sb1.st_size, (sb2.st_size * 100) / sb1.st_size);
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
