     1  #include <fcntl.h>
     2  #include <stdlib.h>
     3  #include <stdio.h>
     4  
     5  int main(int argc, char **argv)
     6  {
     7      if (argc != 2)
     8      {
     9          printf("Please provide the correct number of arguments!\n");
    10          return -1;
    11      }
    12      
    13      int inword = 0;
    14      int numberOfWords = 0;
    15      // Get the filename of the text file
    16      char *file = argv[1];
    17      // A character variable
    18      char ch = ' ';
    19      // Open text file for reading
    20      FILE *fp = fopen(file,"r");
    21  
    22      if (fp == NULL)
    23      {
    24          printf("Error reading %s\n", file);
    25          return 1;
    26      }
    27  
    28      // Start counting words
    29      while( (ch = fgetc(fp)) != EOF )
    30      {
    31          if (ch == ' ' || ch == '\n' || ch == '\t')
    32          {
    33                  inword = 0;
    34          }
    35          else if (inword == 0)
    36          {
    37                  inword = 1;
    38                  numberOfWords++;
    39          }
    40      }
    41      
    42      // Close the file
    43      fclose(fp);
    44      
    45      printf("Number of words found %d\n", numberOfWords);
    46  
    47      return 0;
    48  }