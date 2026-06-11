#include <stdio.h>

int main()
{
    int n;
    char file[10][20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter file %d name: ", i + 1);
        scanf("%s", file[i]);
    }

    printf("\nSingle Level Directory\n");

    for(int i = 0; i < n; i++)
    {
        printf("%s\n", file[i]);
    }

    return 0;
}
