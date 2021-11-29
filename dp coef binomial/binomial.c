//Coeficiente binomial o conbinatoria
#include <stdio.h>
#include <stdlib.h>
#define n 3

//int n=3, k=2;
int contador = 0;
int tabla[n][n];

void dp()
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            tabla[i][j] = -1;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("tabla(%d,%d)=(%d)\n", i, j, tabla[i][j]);
        }
    }
}

int binomio(int n1, int k1)
{
    contador++;

    if (k1 == 0 || k1 == n1)
        return 1;

    else if (k1 > 0 && k1 < n1)
    {
        if (tabla[n1 - 1][k1 - 1] == -1)
            tabla[n1 - 1][k1 - 1] = binomio(n1 - 1, k1 - 1);
        if (tabla[n1 - 1][k1] == -1)
            tabla[n1 - 1][k1] = binomio(n1 - 1, k1);
        return tabla[n1 - 1][k1 - 1] + tabla[n1 - 1][k1];
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n1, k1;
    scanf("%d", &n1);
    scanf("%d", &k1);

    dp();
    printf("%d\n", binomio(n1, k1));
    printf("contador:%d", contador);

    return 0;
}