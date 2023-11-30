#include "iostream"
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include "sys/wait.h"

void func1()
{
  int num;
  std::cout << "Enter an integer\n>> ";
  std::cin >> num;
  std::cout << "The square plus 6 is " << (num * num) + 5 << std::endl;
}
void func2()
{
  int num1, num2, num3;
  std::cout << "Enter an integer\n>> ";
  std::cin >> num1;
  std::cout << "Enter an integer\n>> ";
  std::cin >> num2;
  std::cout << "Enter an integer\n>> ";
  std::cin >> num3;
  std::cout << "The sum is " << (num1 + num2 + num3) << std::endl;
}

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
    func1();
  }
  else
  { /* parent process */
    wait(NULL);
    func2();
  }
  return 0;
}
