#include <stdio.h>
int max(int a, int b) //O(1)
{
  return (a > b) ? a : b; //O(1)
}
int main()
{
  int t;             //O(1)
  scanf("%d\n", &t); //O(1)
  while (t--)        //O(t*(h*w))
  {
    int h, w, i, j;        //O(1)
    scanf("%d%d", &h, &w); //O(1)
    int a[h][w], dp[h][w]; //O(1)

    for (i = 0; i < h; i++) //O(h*w)
      for (j = 0; j < w; j++)
      {
        scanf("%d", &a[i][j]); //O(1)
        dp[i][j] = 0;          //O(1)
      }

    for (i = 0; i < w; i++) //O(w)
      dp[0][i] = a[0][i];   //O(1)

    for (i = 1; i < h; i++) //O(h*w)
    {
      for (j = 0; j < w; j++)
      {
        int x = (j > 0) ? dp[i - 1][j - 1] : 0;     //O(1)
        int y = (j < w - 1) ? dp[i - 1][j + 1] : 0; //O(1)
        int z = dp[i - 1][j];                       //O(1)
        dp[i][j] = a[i][j] + max(x, max(y, z));     //O(1)
      }
    }
    int x = 0;                  //O(1)
    for (i = 0; i < w; i++)     //O(w)
      x = max(x, dp[h - 1][i]); //O(1)
    printf("%d\n", x);          //O(1)
  }
}