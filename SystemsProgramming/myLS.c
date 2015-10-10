     1  #include <fcntl.h>
     2  #include <stdlib.h>
     3  #include <stdio.h>
     4  #include <dirent.h>
     5  
     6  int main(int argc, char **argv)
     7  {
     8      if (argc != 2)
     9      {
    10          printf("Please provide the correct number of arguments!\n");
    11          return -1;
    12      }
    13  
    14      DIR *theDirectory;
    15      struct dirent *entriesP = NULL;
    16  
    17      // Open the directory
    18      if (( theDirectory = opendir(argv[1])) == NULL )
    19      {
    20          printf("Cannot open directory %s.\n", argv[1]);
    21          return -1;
    22      }
    23      
    24      // Read all its entries
    25      while ( (entriesP = readdir(theDirectory)) != NULL )
    26      {
    27          printf("%s\n", entriesP->d_name);
    28      }
    29  
    30      closedir(theDirectory);
    31  
    32      return 0;
    33  }