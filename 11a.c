#include <stdio.h>

int main()
{
    int indexBlock, n;
    int block[20];

    printf("Enter index block: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &block[i]);
    }

    printf("\nIndex Block : %d\n", indexBlock);

    printf("Allocated Blocks : ");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", block[i]);
    }

    return 0;
}
