// ID: 417002714, Name: Aquon Bovell, Date: 11 / 07 / 2023
#include "iostream"
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include "sys/wait.h"
#include <time.h>    /* time */
#include <pthread.h> // for threading

void func1();
void func2();
int Storage[5];

void *thread_func(void *arg)
{
  func1();
  func2();
  pthread_exit(NULL);
}

int main()
{
  pid_t pid1, pid3;

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
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    pthread_join(thread, NULL);

    std::cout << "Child Process completed\n";
  }
  else
  { /* parent process */
    wait(NULL);
    pid3 = fork();
    if (pid3 < 0)
    { /* error occurred */
      fprintf(stderr, "Fork Failed");
      return 1;
    }
    else if (pid3 == 0)
    { /* child process */
      /* fork a child process */
      std::cout << "Thread printing from the parent process\n";
    }
    else
    { /* parent-child process */
      wait(NULL);
      std::cout << "Parent completed\n";
    }
  }
  return 0;
}

void func1()
{
  srand(time(NULL));
  for (int i = 0; i < 5; i++)
  {
    Storage[i] = (int)(rand() % 81) + 20;
    std::cout << Storage[i] << ", ";
  }
}

void func2()
{
  for (int i = 0; i < 5; i++)
  {
    Storage[i] = Storage[i] + 6;
    std::cout << Storage[i] << std::endl;
  }

  int min = Storage[0], max = Storage[0];
  for (int i = 1; i < 5; i++)
  {
    if (min > Storage[i])
    {
      min = Storage[i];
    }
    if (max < Storage[i])
    {
      max = Storage[i];
    }
  }

  std::cout << "The smallest element is " << min << std::endl;
  std::cout << "The largest element is " << max << std::endl;
}
