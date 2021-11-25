#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(long int a, long int b)
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

/*long int lcs(char x[], char y[], long int m, long int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (x[m] == y[n])
    {
        return 1 + lcs(x, y, m - 1, n - 1);
    }
    else
    {
        return max(lcs(x, y, m, n - 1), lcs(x, y, m - 1, n));
    }
}*/

int lcs(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
    that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
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

    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
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