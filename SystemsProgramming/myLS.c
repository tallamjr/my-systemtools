#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Please provide the correct number of arguments!\n");
        return -1;
    }

    DIR *theDirectory;
    struct dirent *entriesP = NULL;

    // Open the directory
    if (( theDirectory = opendir(argv[1])) == NULL )
    {
        printf("Cannot open directory %s.\n", argv[1]);
        return -1;
    }

    // Read all its entries
    while ( (entriesP = readdir(theDirectory)) != NULL )
    {
        printf("%s\n", entriesP->d_name);
    }

    closedir(theDirectory);

    return 0;
}
