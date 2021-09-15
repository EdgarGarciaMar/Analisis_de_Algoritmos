#include <stdlib.h>
#include <stdlib.h>

void sumacuadratica3mayores(int *A, int n)
{
    int m1, m2, m3, i, cont = 0;
    if (A[1] > A[2] && A[1] > A[3])
    {
        m1 = A[1];
        if (A[2] > A[3])
        {
            m2 = A[2];
            m3 = A[3];
        }
        else
        {
            m2 = A[3];
            m3 = A[2];
        }
    }
    else if (A[2] > A[1] && A[2] > A[3])
    {
        m1 = A[2];
        if (A[1] > A[3])
        {
            m2 = A[1];
            m3 = A[3];
        }
        else
        {
            m2 = A[3];
            m3 = A[1];
        }
    }
    else
    {
        m1 = A[3];
        if (A[1] > A[2])
        {
            m2 = A[1];
            m3 = A[2];
        }
        else
        {
            m2 = A[2];
            m3 = A[1];
        }
    }
    i = i + 4;
    while (i <= n)
    {
        if (A[i] > m1)
        {
            m3 = m2;
            m2 = m1;
            m3 = A[i];
        }
        else if (A[i] > m2)
        {
            m3 = m2;
            m2 = A[i];
        }
        else if (A[i] > m3)
        {
            m3 = A[i];
        }
        i = i + 1;
    }
    printf("\n La suma cuadratica de los 3 numeros mayores es: %d\n", pow(m1 + m2 + m3, 2));
    printf("\n Tiempo: %d \n", cont);
}

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
    printf("\n La suma cuadratica de los 3 numeros mayores es: %d\n", pow(r, 2));
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
int main(int argc, char *argv[])
{
    int n, opc;
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
    int A[n];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", A[i]);
    }

    sumacuadratica3mayores(A, n);
    return 0;
}