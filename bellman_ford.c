//Bellman ford

#include <stdio.h>
#define INF 999

int main()
{
    int n, cost[10][10];
    int dist[10];
    int i, j, k, source;

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

    printf("Enter source vertex: ");
    scanf("%d",&source);

    for(i=1;i<=n;i++)
        dist[i]=INF;

    dist[source]=0;

    for(k=1;k<=n-1;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(dist[i] + cost[i][j] < dist[j])
                {
                    dist[j] = dist[i] + cost[i][j];
                }
            }
        }
    }

    printf("\nShortest distances from source:\n");

    for(i=1;i<=n;i++)
        printf("Vertex %d = %d\n", i, dist[i]);

    return 0;
}
