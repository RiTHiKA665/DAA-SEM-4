#include <stdio.h>
#define INF 999

int main()
{
    int n, cost[10][10];
    int dist[10], next[10];
    int i, j, min;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);

            if(cost[i][j]==0 && i!=j)
                cost[i][j]=INF;
        }
    }

    dist[n] = 0;

    for(i=n-1;i>=1;i--)
    {
        min = INF;

        for(j=i+1;j<=n;j++)
        {
            if(cost[i][j] + dist[j] < min)
            {
                min = cost[i][j] + dist[j];
                next[i] = j;
            }
        }

        dist[i] = min;
    }

    printf("\nMinimum cost to reach vertex = %d\n", dist[1]);

    printf("Path: 1");
    i=1;

    while(i!=n)
    {
        i = next[i];
        printf(" -> %d", i);
    }

    return 0;
}
