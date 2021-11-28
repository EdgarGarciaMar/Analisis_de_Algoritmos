#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; } //O(1)

void printknapSack(int W, int wt[], int val[], int n) //O(n*w)
{
    int i, w;            //O(1)
    int K[n + 1][W + 1]; //O(1)

    for (i = 0; i <= n; i++) //O(n)
    {
        for (w = 0; w <= W; w++) //O(w)
        {
            if (i == 0 || w == 0)    //O(1)
                K[i][w] = 0;         //O(1)
            else if (wt[i - 1] <= w) //O(1)
                K[i][w] = max(val[i - 1] +
                                  K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]); //O(1)
            else
                K[i][w] = K[i - 1][w]; //O(1)
        }
    }

    int res = K[n][W];
    printf("%d\n", res); //O(1)
}

int main()
{
    int s, n, i;

    scanf("%d %d", &s, &n);

    int val[n];
    int wt[n];

    for (i = 0; i < n; ++i)
    {
        scanf("%d %d", &wt[i], &val[i]);
    }

    printknapSack(s, wt, val, n);

    return 0;
}