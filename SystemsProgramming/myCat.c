#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

void cat(int f, char *s)
{
    char buf[2048];
    long n;
    while ((n=read(f, buf, (long) sizeof(buf))) > 0)
        if(write(1, buf, n) != n)
            printf("Error while printing output!\n");

    if(n<0)
        printf("Error reading %s!\n", s);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        printf("You have to give a filename!\n");
    
    int f = open(argv[1], O_RDONLY);
    if (f < 0)
        printf("Cannot open file!\n");
    else
        cat(f, argv[1]);

    return 0;
}