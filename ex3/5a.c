#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include "sys/wait.h"

int main()
{
  pid_t pid, pid1;
  /* fork a child process */
  pid = fork();
  int start, end;
  if (pid < 0)
  { /* error occurred */
    fprintf(stderr, "Fork Failed");
    return 1;
  }
  else if (pid == 0)
  { /* child process */
    start = 0;
    end = 25;
  }
  else
  { /* parent process */
    start = 25;
    end = 51;
    wait(NULL);
  }

  for (int i = start; i < end; i++)
  {
    printf("%d, ", i);
  }
  return 0;
}