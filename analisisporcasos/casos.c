#include <stdio.h>
#include <stdlib.h>

void sumacuadratica3mayores(int A[], int n)
{
    int m1, m2, m3, i, cont = 0;
    if (A[1] > A[2] && A[1] > A[3])
    {
        cont += 2; //2 comparaciones if
        m1 = A[1];
        cont++; //1 asignación m1
        if (A[2] > A[3])
        {
            cont++; //1 comparación if
            m2 = A[2];
            cont++;
            m3 = A[3];
            cont++;
        }
        else
        {
            cont++; //falso if
            m2 = A[3];
            cont++;
            m3 = A[2];
            cont++;
        }
    }
    else if (A[2] > A[1] && A[2] > A[3])
    {
        cont += 2; //2 comparaciones falso if
        m1 = A[2];
        cont++; //1 asignación
        if (A[1] > A[3])
        {
            cont++; //1 comparación
            m2 = A[1];
            m3 = A[3];
            cont += 2; //2 asignaciones
        }
        else
        {
            cont++; //falso if
            m2 = A[3];
            m3 = A[1];
            cont += 2; //2 asignaciones
        }
    }
    else
    {
        cont += 2; //falso if
        m1 = A[3];
        cont++; //1 asignación
        if (A[1] > A[2])
        {
            cont++; //1 comparación
            m2 = A[1];
            m3 = A[2];
            cont += 2; //2 asignaciones
        }
        else
        {
            cont++; //falso if
            m2 = A[2];
            m3 = A[1];
            cont += 2; //2 asignaciones
        }
    }
    i = 4;
    while (i <= n)
    {
        cont += 3;
        if (A[i] > m1)
        {
            cont++; //1 comparación
            m3 = m2;
            m2 = m1;
            m1 = A[i];
            cont += 3; //asignaciones
        }
        else if (A[i] > m2)
        {
            cont++; //1 comparación
            m3 = m2;
            m2 = A[i];
            cont += 2; //asignaciones
        }
        else if (A[i] > m3)
        {
            cont++; //1 comparación
            m3 = A[i];
            cont++; //asignaciones
        }
        i = i + 1;
    }
    int suma = (m1 * m1) + (m2 * m2) + (m3 * m3);
    printf("\n %d + %d + %d al cuadrado es: %d\n", m1, m2, m3, suma);
    printf("\n Tiempo: %d \n", cont);
}
/*
void maximoComunDivisor(int m, int n)
{
    int a, b, residuo, maximocomundivisor, cont = 0;
    a = max(n, m);
    b = min(n, m);
    residuo = 1;
    while (residuo > 0)
    {
        residuo = a % b;
        a = b;
        b = residuo;
    }
    maximocomundivisor = a;
    printf("\n El maximo comun divisor es: %d\n", maximoComunDivisor);
    printf("\n Tiempo: %d \n", cont);
}

void sumacuadratica3mayoresv2(int *A, int n)
{
    int aux, r, cont = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
        }
    }
    r = A[n - 1] + A[n - 2] + A[n - 3];
    printf("\n La suma cuadratica de los 3 numeros mayores es: %f\n", pow(r, 2));
    printf("\n Tiempo: %d \n", cont);
}

void codigo5(int n, int *A)
{
    int polinomio, z;
    for (int i = 0; i <= n; i++)
    {
        polinomio = polinomio * z + A[n - i];
    }
}
*/
int main(int argc, char *argv[])
{
    int n;

    if (argc != 2)
    {
        printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100 \n", argv[0]);
        exit(1);
    }
    //Tomar el segundo argumento como tamaño del algoritmo
    else
    {
        n = atoi(argv[1]);
    }
    // Lectura del archivo numeros10millones.txt mediante redireccionamiento.
    int A[n];
    for (int a = 0; a <= n; a++)
    {
        scanf("%d", &A[a]);
        //printf("[%d]=%d\n", a, A[a]);
    }

    sumacuadratica3mayores(A, n);
    /*for (int i = 0; i < n; i++)
    {
        printf("%d\n", i);
    }*/

    return 0;
}