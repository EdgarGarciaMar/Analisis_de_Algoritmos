#include <stdio.h>
#include <stdlib.h>

void mcdo(int a, int b) //Maximo Comun Divisor Operacion
{
    int ban = 0;
    int aux1 = a;
    int aux2 = b;
    int aux3;

    aux3 = aux1 % aux2;
    if (aux3 == 0)
    {
        printf("El maximo comun divisor es: %d", aux2);
        printf("\n");
    }
    else
    {
        while (ban == 0)
        {
            aux1 = aux2;
            aux2 = aux3;
            aux3 = aux1 % aux2;
            if (aux3 == 0)
            {
                printf("El maximo comun divisor es: %d", aux2);
                printf("\n");
                ban = 1;
            }
        }
    }
}

void menu()
{
    int a, b;
    int opc;
    for (;;)
    {
        printf("MCD\n");
        printf("1: sacar MCD\n");
        printf("2: salir\n");
        printf("Selecciona una opcion:\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("Ingresa el numero 1: \n");
            scanf("%d", &a);
            printf("Ingresa el numero 2: \n");
            scanf("%d", &b);
            mcdo(a, b);
            system("read -n 1 -s -p \"Press any key to continue...\""); //system("pause"); en MacOS
            system("clear");
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("Selecciona una de las opciones:\n");
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