#include <stdlib.h>
#include <stdio.h>

int scanearn()
{
    int n;
    puts("Ingresa n:");
    scanf("%d", &n);
    return n;
}

void c1()
{
    printf("hola");
}
void c2()
{
    int n = scanearn();
    int n_espacio = 0, n_tiempo = 0;

    int polinomio, i, z = 0, *A;
    n_espacio += 3;
    A = malloc(sizeof(int *) * (n));
    n_espacio += n;
    //******************************
    polinomio = 0;
    n_tiempo++;
    n_espacio++;
    for (i = 0, n_tiempo++; i <= n; n_tiempo++, i++)
    {
        n_tiempo++; //verdadero
        polinomio = polinomio * z + A[n - i];
        n_tiempo += 4;
    }
    n_tiempo++; //falso
    //*********************************
    printf("Espacio:%d\n", n_espacio);
    printf("Tiempo:%d\n", n_tiempo);
}

void c3()
{
    int n = scanearn();
    int n_espacio = 0, n_tiempo = 0;

    int i, j, k, **a, **b, **c;
    a = malloc(sizeof(int *) * (n * n));
    b = malloc(sizeof(int *) * (n * n));
    c = malloc(sizeof(int *) * (n * n));

    //*************************
    /*for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            c[i, j] = 0;
            for (k = 1; k < n; k++)
            {
                c[i, j] = c[i, j] + a[i, k] * b[k, j];
            }
        }
    }*/
    //*******************************
    printf("Espacio:%d\n", n_espacio);
    printf("Tiempo:%d\n", n_tiempo);
}

void c4()
{
    int n = scanearn();
    int n_espacio = 0, n_tiempo = 0;

    int anterior, aux, actual;
    n_espacio += 3;
    //****************************************
    anterior = 1;
    n_tiempo++;
    actual = 1;
    n_tiempo++;
    while (n > 2)
    {
        n_tiempo++; // verdad
        aux = anterior + actual;
        n_tiempo += 2;
        anterior = actual;
        n_tiempo++;
        actual = aux;
        n_tiempo++;
        n = n - 1;
        n_tiempo += 2;
    }
    n_tiempo++; // falso
    //*******************************************

    printf("Espacio:%d\n", n_espacio);
    printf("Tiempo:%d\n", n_tiempo);
}
void menu()
{
    int opc;
    for (;;)
    {
        printf("Funciones de complejidad\n");
        printf("1: Codigo 1\n");
        printf("2: Codigo 2\n");
        printf("3: Codigo 3\n");
        printf("4: Codigo 4\n");
        printf("5: Codigo 5\n");
        printf("6: Codigo 6\n");
        printf("7: Codigo 7\n");
        printf("8: Salir\n");
        printf("Selecciona una opcion\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            c1();
            break;
        case 2:
            c2();
            break;
        case 3:
            c3();
            break;
        case 4:
            c4();
            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Selecciona una opcion del menu\n");
            menu();
            break;
        }
    }
}
int main()
{
    menu();
    return 0;
}