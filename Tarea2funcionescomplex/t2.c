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
    n_espacio += 3;
    n_espacio = n_espacio + (3 * n * n);
    //Asignacion de espacio de matriz 2x2
    a = malloc(sizeof(int *) * (n));
    b = malloc(sizeof(int *) * (n));
    c = malloc(sizeof(int *) * (n));

    for (int m = 0; m < n; m++)
    {
        a[m] = malloc(sizeof(int));
        b[m] = malloc(sizeof(int));
        c[m] = malloc(sizeof(int));
    }

    //*************************
    for (i = 1, n_tiempo++; i < n; n_tiempo++, i++)
    {
        n_tiempo++; //verdad
        for (j = 1, n_tiempo++; j < n; n_tiempo++, j++)
        {
            n_tiempo++; //verdad2
            c[i][j] = 0;
            n_tiempo++;
            for (k = 1, n_tiempo++; k < n; n_tiempo++, k++)
            {
                n_tiempo++; //verdad3
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
                n_tiempo += 3;
            }
            n_tiempo++; //falso3
        }
        n_tiempo++; //falso2
    }
    n_tiempo++; //falso
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
void c5()
{
    int n = scanearn();
    int n_espacio = 0, n_tiempo = 0;

    //
    int i, j, k, *s, *s2;
    s = malloc(sizeof(int *) * (n));
    s2 = malloc(sizeof(int *) * (n));
    n_espacio += 3;
    n_espacio = n_espacio + (2 * n);
    //*******************************************
    for (i = n - 1, j = 0, n_tiempo += 2; i >= 0; i--, j++, n_tiempo += 2)
    {
        n_tiempo++; //verdad1
        s2[j] = s[i];
        n_tiempo++;
    }
    n_tiempo++; //falso1
    for (k = 0, n_tiempo++; k < n; n_tiempo++, k++)
    {
        n_tiempo++; //verdad2
        s[i] = s2[i];
        n_tiempo++;
    }
    n_tiempo++; //falso2
    //***************************************************

    printf("Espacio:%d\n", n_espacio);
    printf("Tiempo:%d\n", n_tiempo);
}
void c6()
{
    printf("\nn no requerida.\n");
    int n_espacio = 0, n_tiempo = 0;

    //almacenamiento
    int l, a, b, i, r;
    n_espacio += 5;
    //*********************************************
    l = (a < b) ? a : b;
    n_tiempo += 4; //operador terniario
    r = 1;
    n_tiempo++;
    for (i = 2, n_tiempo++; i <= l; n_tiempo++, i++)
    {
        n_tiempo++; //verdad for
        if (a % i == 0 && b % i == 0)
        {
            n_tiempo += 2; //verdadif
            r = i;
            n_tiempo++;
        }
        n_tiempo++; //falsoif
    }
    n_tiempo++; //falso for
    printf("Espacio sin n:%d\n", n_espacio);
    printf("Tiempo sin n:%d\n", n_tiempo);
}
void c7()
{
    printf("hola");
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
            c5();
            break;
        case 6:
            c6();
            break;
        case 7:
            c7();
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