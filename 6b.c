#include <stdio.h>

int main()
{
    int n, f, page[50], frame[10];
    int i, j, k, found, fault = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        // Check if page is already present
        for(j = 0; j < f; j++)
        {
            if(frame[j] == page[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            int pos = -1;

            // Fill empty frame first
            for(j = 0; j < f; j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find optimal replacement
            if(pos == -1)
            {
                int farthest = -1;

                for(j = 0; j < f; j++)
                {
                    int next;

                    for(next = i + 1; next < n; next++)
                    {
                        if(frame[j] == page[next])
                            break;
                    }

                    if(next == n)
                    {
                        pos = j;
                        break;
                    }

                    if(next > farthest)
                    {
                        farthest = next;
                        pos = j;
                    }
                }
            }

            frame[pos] = page[i];
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
