#include <stdio.h>

int main() {
    int f[50], i, j, st, len, n;

    // Initialize all blocks as free
    for(i = 0; i < 50; i++)
        f[i] = 0;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter starting block and length of file %d: ", i + 1);
        scanf("%d%d", &st, &len);

        int flag = 0;

        // Check if required blocks are free
        for(j = st; j < st + len; j++) {
            if(f[j] == 1) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            for(j = st; j < st + len; j++)
                f[j] = 1;

            printf("File allocated successfully.\nBlocks allocated: ");
            for(j = st; j < st + len; j++)
                printf("%d ", j);
            printf("\n");
        }
        else {
            printf("Allocation not possible.\n");
        }
    }

    return 0;
}
