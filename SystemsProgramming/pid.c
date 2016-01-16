#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        printf("There is no need for command line arguments!\n");
        return -1;
    }

    int pid = getpid();
    int ppid = getppid();

    if ( pid > 0 )
    {
        printf("Your process id is %d\n", pid);
    }
    else
    {
        printf("There is an error with your process id %d\n", pid);
    }

    if ( ppid > 0 )
    {
        printf("You have been called from a process with id %d!\n", ppid);
    }
    else
    {
        printf("There was an error while getting parent process id: %d!\n", ppid);
    }

    return 0;
}
