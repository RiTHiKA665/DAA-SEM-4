#include <stdio.h>
int n;
int cost[10][10];
int assigned[10], tempassign[10], bestassign[10];
int mincost = 999;
void assign(int person, int total)
{
    int i;
    if (person == n)
    {
        if (total < mincost)
        {
            mincost = total;
            for (i = 0; i < n; i++)
                bestassign[i] = tempassign[i];
        }
        return;
    }
    for (i = 0; i < n; i++)
    {
        if (!assigned[i])
        {
            assigned[i] = 1;
            tempassign[person] = i;
            assign(person + 1, total + cost[person][i]);
            assigned[i] = 0;
        }
    }
}
int main()
{
    int i, j;
    printf("Enter number of persons/jobs: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
         for (j = 0; j < n; j++)
         scanf("%d", &cost[i][j]);
    for (i = 0; i < n; i++)
        assigned[i] = 0;
    assign(0, 0);
    printf("\nMinimum Assignment Cost = %d\n", mincost);
    printf("Optimal Assignment:\n");
    for (i = 0; i < n; i++)
    {
        printf("Person %d -> Job %d (Cost = %d)\n",
               i + 1, bestassign[i] + 1,
               cost[i][bestassign[i]]);
    }
    return 0;
}
