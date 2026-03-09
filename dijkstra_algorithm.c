//Dijkstra algortihm
#include <stdio.h>
#define INF 9999
int main()
{
    int n, cost[10][10];
    int status[10], dist[10];
    int i, j, source, current, min;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0 && i!=j)
                cost[i][j]=INF;
        }
    }
    printf("Enter source vertex: ");
    scanf("%d",&source);
    source = source - 1;
    for(i=0;i<n;i++)
    {
        status[i] = 0;   
        dist[i] = INF;
    }
    dist[source] = 0;
    while(1)
    {
        min = INF;
        current = -1;
        for(i=0;i<n;i++)
        {
            if(status[i]==0 && dist[i] < min)
            {
                min = dist[i];
                current = i;
            }
        }
        if(current == -1)
            break;
        status[current] = 1;
        for(j=0;j<n;j++)
        {
            if(status[j]==0)
            {
                if(dist[current] + cost[current][j] < dist[j])
                {
                    dist[j] = dist[current] + cost[current][j];
                }
            }
        }
    }
    printf("\nShortest distances from source:\n");
    for(i=0;i<n;i++)
    {
        printf("Distance to vertex %d = %d\n", i+1, dist[i]);
    }
    return 0;
}
