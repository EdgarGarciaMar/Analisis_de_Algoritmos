#include <stdio.h>
#include <stdlib.h>

void c1prueba()
{
    int n;
    puts("Ingresa n:");
    scanf("%d", &n);
    int k = 1;

    for (int i = 10; i < n * 5; i *= 2)
    {
        printf("[%d]Algoritmo\n", k);
        k++;
    }
}

void c2prueba()
{
    int n;
    puts("Ingresa n:");
    scanf("%d", &n);
    int k = 1;
    for (int j = n; j > 1; j /= 2)
    {
        if (j < (n / 2))
        {
            for (int i = 0; i < n; i += 2)
            {
                printf("[%d]Algoritmos\n", k);
                k++;
            }
        }
    }
}

void c3prueba()
{
    int n;
    puts("Ingresa n:");
    scanf("%d", &n);
    int con = 1;
    for (int i = 0; i < n * 5; i += 2)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            for (int k = j; k < n; k++)
            {
                printf("[%d]Algoritmos\n", con);
                con++;
            }
        }
    }
}

void c4prueba()
{
    int n;
    puts("Ingresa n:");
    scanf("%d", &n);
    int k = 1;
    int i = n;
    while (i >= 0)
    {
        for (int j = n; i < j; i -= 2, j /= 2)
        {
            printf("[%d]Algoritmos\n", k);
            k++;
        }
    }
}

void c5prueba()
{
    int n;
    puts("Ingresa n:");
    scanf("%d", &n);
    int k = 1;
    for (int i = 1; i < 4 * n; i *= 2)
    {
        for (int j = i; j < 5 * n; j += 3)
        {
            printf("[%d]Algoritmos\n", k);
            k++;
        }
    }
}

void menu()
{
    int opc;
    for (;;)
    {
        printf("Numero de Impresiones\n");
        printf("1: Codigo 1\n");
        printf("2: Codigo 2\n");
        printf("3: Codigo 3\n");
        printf("4: Codigo 4\n");
        printf("5: Codigo 5\n");
        printf("6: Salir\n");
        printf("Selecciona una opcion\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            c1prueba();
            break;
        case 2:
            c2prueba();
            break;
        case 3:
            c3prueba();
            break;
        case 4:
            c4prueba();
            break;
        case 5:
            c5prueba();
            break;
        case 6:
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
