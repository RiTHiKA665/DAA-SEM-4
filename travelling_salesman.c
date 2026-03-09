//Travelling salesman 

#include <stdio.h>
#define INF 999

int cost[10][10], visited[10], n;

int tsp(int city)
{
    int i, next_city = -1;
    int min = INF, temp;
    int total = 0;

    visited[city] = 1;
    printf("%d ", city + 1);

    for(i=0;i<n;i++)
    {
        if(cost[city][i] != 0 && visited[i] == 0)
        {
            if(cost[city][i] < min)
            {
                min = cost[city][i];
                next_city = i;
            }
        }
    }

    if(next_city == -1)
    {
        printf("1 ");
        return cost[city][0];
    }

    total = min + tsp(next_city);

    return total;
}

int main()
{
    int i,j;
    int total_cost;

    printf("Enter number of cities: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }

    for(i=0;i<n;i++)
        visited[i]=0;

    printf("Path: ");

    total_cost = tsp(0);

    printf("\nMinimum travelling cost = %d\n", total_cost);

    return 0;
}
