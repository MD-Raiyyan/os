#include <stdio.h>

int main()
{
    int n, f, page[50], frame[10], recent[10];
    int i, j, found, fault = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        frame[i] = -1;
        recent[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == page[i])
            {
                found = 1;
                recent[j] = i;
                break;
            }
        }

        if(found == 0)
        {
            int pos = 0;

            for(j = 1; j < f; j++)
            {
                if(recent[j] < recent[pos])
                    pos = j;
            }

            frame[pos] = page[i];
            recent[pos] = i;
            fault++;
        }

        printf("Frames: ");
        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);

        printf("\n");
    }

    printf("Total Page Faults = %d\n", fault);

    return 0;
}
