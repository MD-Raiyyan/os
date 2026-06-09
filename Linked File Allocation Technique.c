#include<stdio.h>

int main()
{
    int f[50], i, n, start, len, block;

    for(i = 0; i < 50; i++)
        f[i] = 0;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter number of blocks: ");
    scanf("%d", &len);

    printf("Enter block numbers:\n");

    printf("%d -> ", start);
    f[start] = 1;

    for(i = 1; i < len; i++)
    {
        scanf("%d", &block);

        if(f[block] == 0)
        {
            f[block] = 1;
            printf("%d -> ", block);
        }
        else
        {
            printf("Block already allocated\n");
            return 0;
        }
    }

    printf("NULL\n");

    return 0;
}
