#include <stdio.h>

int main()
{
    int n, pagesize;
    int frame[20];
    int pageno, offset, physical;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page size: ");
    scanf("%d", &pagesize);

    // Page Table
    for(int i = 0; i < n; i++)
    {
        printf("Enter frame number for page %d: ", i);
        scanf("%d", &frame[i]);
    }

    printf("Enter page number: ");
    scanf("%d", &pageno);

    printf("Enter offset: ");
    scanf("%d", &offset);

    if(pageno >= n || offset >= pagesize)
    {
        printf("Invalid Address\n");
    }
    else
    {
        physical = frame[pageno] * pagesize + offset;

        printf("Frame Number = %d\n", frame[pageno]);
        printf("Physical Address = %d\n", physical);
    }

    return 0;
}
