/* Dynamic Programming C++ implementation
   of LIS problem */
#include <bits/stdc++.h>
using namespace std;
/* lis() returns the length of the longest
  increasing subsequence in arr[] of size n */
int lis(int arr[], int n)
{
    int lis[n];

    lis[0] = 1;

    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    // Return maximum value in lis[]
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