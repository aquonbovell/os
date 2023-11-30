#include <stdio.h>
#include <unistd.h>
int main()
{
  /* fork a child process */
  fork();
  /* fork another child process */
  printf("Hello world\n");
  fork();
  /* and fork another */
  fork();
  // printf("Hello world\n");
  return 0;
}