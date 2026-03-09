//knap sack 0-1 method

#include <stdio.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int n,W;
    int p[10],w[10];
    int K[10][10];
    int i,j;

    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter profits:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);

    printf("Enter weights:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d",&W);

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                K[i][j]=0;

            else if(w[i] <= j)
                K[i][j] = max(K[i-1][j], p[i] + K[i-1][j-w[i]]);

            else
                K[i][j] = K[i-1][j];
        }
    }

    printf("Maximum Profit = %d\n",K[n][W]);

    return 0;
}
