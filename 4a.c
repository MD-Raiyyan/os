#include <stdio.h>
#include <unistd.h>

int global = 10;

int main()
{
    int local = 20;

    pid_t pid = fork();

    if(pid == 0)
    {
        // Child Process
        global = 100;
        local = 200;

        printf("Child Process\n");
        printf("Global = %d\n", global);
        printf("Local = %d\n", local);
    }
    else
    {
        // Parent Process
        sleep(1);

        printf("Parent Process\n");
        printf("Global = %d\n", global);
        printf("Local = %d\n", local);
    }

    return 0;
}
