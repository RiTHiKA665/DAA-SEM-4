//Multistage forward
#include<stdio.h>
#define INF 999
int main()
{
    int n, cost[10][10];
    int dist[10], pred[10];
    int i,j,min;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter cost adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0 && i!=j)
                cost[i][j]=INF;
        }
    }
    dist[1]=0;
    for(i=2;i<=n;i++)
    {
        min=INF;
        for(j=1;j<i;j++)
        {
            if(cost[j][i]!=INF && dist[j]+cost[j][i] < min)
            {
                min = dist[j] + cost[j][i];
                pred[i] = j;
            }
        }
        dist[i] = min;
    }
    printf("\nMinimum cost to reach vertex %d = %d\n",n,dist[n]);

    printf("Path: %d",n);
    j=n;
    while(j>1)
    {
        j=pred[j];
        printf(" <- %d",j);
    }
    return 0;
}
