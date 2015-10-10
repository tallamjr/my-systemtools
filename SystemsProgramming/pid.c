     1  #include <stdlib.h>
     2  #include <stdio.h>
     3  #include <unistd.h>
     4  
     5  int main(int argc, char **argv)
     6  {
     7      if (argc != 1)
     8      {
     9          printf("There is no need for command line arguments!\n");
    10          return -1;
    11      }
    12      
    13      int pid = getpid();
    14      int ppid = getppid();
    15  
    16      if ( pid > 0 )
    17      {
    18          printf("Your process id is %d\n", pid);
    19      }
    20      else
    21      {
    22          printf("There is an error with your process id %d\n", pid);
    23      }
    24  
    25      if ( ppid > 0 )
    26      {
    27          printf("You have been called from a process with id %d!\n", ppid);
    28      }
    29      else
    30      {
    31          printf("There was an error while getting parent process id: %d!\n", ppid);
    32      }
    33      
    34      return 0;
    35  }