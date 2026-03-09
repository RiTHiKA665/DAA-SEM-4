//Prims algortihm
#include <stdio.h>
#define INF 9999

int main()
{
    int n, cost[10][10];
    int status[10], min, i, j;
    int current, total_cost = 0;
    int edge_count = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=INF;
        }
    }
    for(i=0;i<n;i++)
        status[i]=0;  

    current = 0;
    status[current] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edge_count < n-1)
    {
        min = INF;
        int x=-1, y=-1;
        for(i=0;i<n;i++)
        {
            {
                for(j=0;j<n;j++)
                {
                    if(status[j]==0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if(y!=-1)
        {
            printf("%d -> %d  cost = %d\n", x+1, y+1, min);
            total_cost += min;
            status[y] = 1;
            edge_count++;
        }
    }
    printf("Minimum Cost = %d\n", total_cost);
    return 0;
}
