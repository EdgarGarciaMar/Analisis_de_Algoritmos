#include <stdio.h>
int max(int a,int b)
{
  return (a>b)?a:b;
}
int main()
{
  int t;
  scanf("%d\n", &t);
  while(t--)
  {
    int h,w,i,j;
    scanf("%d%d", &h,&w);
    int a[h][w],dp[h][w];
    for(i=0;i<h;i++)for(j=0;j<w;j++){scanf("%d",&a[i][j] );dp[i][j]=0;}
    for(i=0;i<w;i++)dp[0][i]=a[0][i];
    for(i=1;i<h;i++)
    {
      for(j=0;j<w;j++)
      {
        int x=(j>0)?dp[i-1][j-1]:0;
        int y=(j<w-1)?dp[i-1][j+1]:0;
        int z=dp[i-1][j];
        dp[i][j]=a[i][j]+max(x,max(y,z));
      }
    }
    int x=0;
    for(i=0;i<w;i++)x=max(x,dp[h-1][i]);
    printf("%d\n", x);
  }
}