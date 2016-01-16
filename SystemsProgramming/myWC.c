#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Please provide the correct number of arguments!\n");
        return -1;
    }

    int inword = 0;
    int numberOfWords = 0;
    // Get the filename of the text file
    char *file = argv[1];
    // A character variable
    char ch = ' ';
    // Open text file for reading
    FILE *fp = fopen(file,"r");

    if (fp == NULL)
    {
        printf("Error reading %s\n", file);
        return 1;
    }

    // Start counting words
    while( (ch = fgetc(fp)) != EOF )
    {
        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            inword = 0;
        }
        else if (inword == 0)
        {
            inword = 1;
            numberOfWords++;
        }
    }

    // Close the file
    fclose(fp);

    printf("Number of words found %d\n", numberOfWords);

    return 0;
}
