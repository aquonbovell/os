#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/wait.h"

int main(int argc, char *argv[])
{
  int id1 = fork();
  int id2 = fork();

  if (id1 == 0)
  {
    if (id2 == 0)
    {
      printf("We are in process y\n");
    }
    else
    {
      sleep(2);
      printf("We are in process x\n");
    }
  }
  else
  {
    if (id2 == 0)
    {
      printf("We are in process z\n");
    }
    else
    {
      wait(NULL);
      printf("We are in the main\n");
    }
  }
  return 0;
}