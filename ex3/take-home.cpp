// ID: 417002714, Name: Aquon Bovell, Date: 11 / 06 / 2023
#include "iostream"
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include "sys/wait.h"

void f1()
{
  for (size_t i = 10; i <= 25; i++)
  {
    std::cout << i << ",";
  }
}

void f2()
{
  for (size_t i = 26; i <= 75; i++)
  {
    std::cout << i << ",";
  }
}

void f3()
{
  for (size_t i = 76; i <= 100; i++)
  {
    if (i == 100)
      std::cout << i << std::endl;
    else
      std::cout << i << ",";
  }
}

int main()
{
  pid_t pid1, pid2;

  /* fork a child process */
  pid1 = fork();

  if (pid1 < 0)
  { /* error occurred */
    fprintf(stderr, "Fork Failed");
    return 1;
  }
  else if (pid1 == 0)
  { /* child process */
    /* fork a child process */
    pid2 = fork();

    if (pid2 < 0)
    { /* error occurred */
      fprintf(stderr, "Fork Failed");
      return 1;
    }
    else if (pid2 == 0)
    { /* child process */
      f1();
    }
    else
    { /* parent-child process */
      wait(NULL);
      f2();
    }
  }
  else
  { /* parent process */
    wait(NULL);
    f3();
  }
  return 0;
}