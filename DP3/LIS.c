
#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int n)
{
    int lis[n]; //O(1)

    lis[0] = 1; //O(1)

    for (int i = 1; i < n; i++) //O(n*i)
    {
        lis[i] = 1;                                     //O(1)
        for (int j = 0; j < i; j++)                     //O(i)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) //O(1)
                lis[i] = lis[j] + 1;                    //O(1)
    }
    return *max_element(lis, lis + n);
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d", lis(a, n));

    return 0;
}