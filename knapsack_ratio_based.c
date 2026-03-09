//Knapsack ratio based
#include <stdio.h>

int main()
{
    int i, j, n, capacity;
    float ratio[10], w[10], p[10], x[10], temp;
    float tot_profit = 0;
    printf("Enter number of items: ");
        scanf("%d",&n);
    printf("Enter profits:\n");
    for(i=0;i<n;i++)
        scanf("%f",&p[i]);
    printf("Enter weights:\n");
    for(i=0;i<n;i++)
        scanf("%f",&w[i]);
    for(i=0;i<n;i++)
        ratio[i] = p[i]/w[i];
    for(i=0;i<n;i++)
        {for(j=i+1;j<n;j++)
            {if(ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }}}
    for(i=0;i<n;i++)
        x[i] = 0;
    printf("Enter capacity: ");
    scanf("%d",&capacity);
    for(i=0;i<n;i++)
    {
        if(w[i] <= capacity)
        {
            x[i] = 1;
            tot_profit += p[i];
            capacity -= w[i];
        }
        else
        {
            x[i] = capacity / w[i];
            tot_profit += x[i] * p[i];
            break;
        }
    }
    printf("Maximum profit = %.2f\n",tot_profit);
    return 0;
}
