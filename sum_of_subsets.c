#include <stdio.h>
int w[10], x[10];
int n, m;

void subset(int sum, int k, int r)
{
    int i;
    if (sum == m)
    {
        printf("Subset: ");
        for (i = 0; i < k; i++)
        {
            if (x[i] == 1)
            printf("%d ", w[i]);
        }
        printf("\n");
        return;
    }
    if (k >= n)
        return;
    if (sum + w[k] <= m)
    {
        x[k] = 1;
        subset(sum + w[k], k + 1, r - w[k]);
    }
    x[k] = 0;
    subset(sum, k + 1, r - w[k]);
}
int main()
{
    int i, total = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        total += w[i];
    }
    printf("Enter required sum: ");
    scanf("%d", &m);
    subset(0, 0, total);
    return 0;
}
