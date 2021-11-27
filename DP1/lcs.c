#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(long int a, long int b) //O(1)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int lcs(char *X, char *Y, int m, int n) //O(m*n)
{
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[m][n];
}

int main()
{
    char x[1000];
    char y[1000];
    int m, n;

    scanf("%s", x);
    scanf("%s", y);

    m = strlen(x);
    n = strlen(y);

    printf("%d", lcs(x, y, m, n));
    return 0;
}