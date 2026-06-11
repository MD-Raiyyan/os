#include <stdio.h>

int main()
{
    int n, base[10], limit[10];
    int seg, offset;

    printf("Enter number of segments: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter base and limit for segment %d: ", i);
        scanf("%d%d", &base[i], &limit[i]);
    }

    printf("Enter segment number: ");
    scanf("%d", &seg);

    printf("Enter offset: ");
    scanf("%d", &offset);

    if(offset < limit[seg])
    {
        printf("Physical Address = %d\n", base[seg] + offset);
    }
    else
    {
        printf("Invalid Address\n");
    }

    return 0;
}
