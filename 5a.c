#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int shmid;
    char *data;

    // Create shared memory
    shmid = shmget(1234, 100, 0666 | IPC_CREAT);

    // Attach shared memory
    data = (char *)shmat(shmid, NULL, 0);

    if (fork() == 0)
    {
        // Child -> Consumer
        sleep(1);   // Wait for producer

        printf("Consumer read: %s\n", data);
    }
    else
    {
        // Parent -> Producer
        strcpy(data, "Hello from Producer");

        printf("Producer wrote: %s\n", data);
    }

    // Detach shared memory
    shmdt(data);

    // Remove shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
