// ID: 417002714, Name: Aquon Bovell, Date: 11 / 07 / 2023
#include "iostream"
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include "sys/wait.h"

void func1()
{
  int num;
  do
  {
    std::cout << "Enter an integer which is greater than 5 but less than 15 \n>>";
    std::cin >> num;
  } while (num <= 5 || num >= 15);
  int sum = 0;
  for (int i = 1; i < num; i++)
  {
    sum = i * i;
  }
  std::cout << "The sum of the squares from 1 to " << num << " is = " << sum << std::endl;
}

void func2()
{
  int num1, num2, num3;
  do
  {
    std::cout << "Num1: Enter an integer which is greater than 5 but less than 20 \n>>";
    std::cin >> num1;
  } while (num1 <= 5 || num1 >= 20);
  do
  {
    std::cout << "Num2: Enter an integer which is greater than 5 but less than 20 \n>>";
    std::cin >> num2;
  } while (num2 <= 5 || num2 >= 20);
  do
  {
    std::cout << "Num3: Enter an integer which is greater than 5 but less than 20 \n>>";
    std::cin >> num3;
  } while (num3 <= 5 || num3 >= 20);

  std::cout << "The prodcut is " << num1 * num2 * num3 << std::endl;
}

int main()
{
  pid_t pid1;

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
    func1();
  }
  else
  { /* parent process */
    wait(NULL);
    func2();
  }
  return 0;
}