#include <stdio.h>

int main()
{
    int nb, np;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[20], process[20], allocation[20];

    for(int i = 0; i < nb; i++)
    {
        printf("Enter size of Block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    for(int i = 0; i < np; i++)
    {
        printf("Enter size of Process %d: ", i + 1);
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    // First Fit Allocation
    for(int i = 0; i < np; i++)
    {
        for(int j = 0; j < nb; j++)
        {
            if(block[j] >= process[i])
            {
                allocation[i] = j;
                block[j] = block[j] - process[i];
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock\n");

    for(int i = 0; i < np; i++)
    {
        printf("P%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
