#include "iostream"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

int *result = new int;

void *func1(void *arg);
void *func2(void *arg);

int main()
{
  pthread_t thread1;
  pthread_t thread2;

  pthread_mutex_init(&mutex, NULL);

  pthread_create(&thread2, NULL, func2, NULL);

  pthread_create(&thread1, NULL, func1, (void *)result);

  pthread_join(thread2, NULL);

  pthread_join(thread1, NULL);

  return 0;
}

void *func1(void *arg)
{
  int *res = (int *)arg;
  pthread_mutex_lock(&mutex);
  int number, sum = 0;
  std::cout << "Enter a number \n>>";
  std::cin >> number;

  for (size_t i = 0; i < number; i++)
  {
    sum += (i + 1);
  }
  std::cout << "The sum is: " << sum << std::endl;
  std::cout << "The divison is: " << sum / *res << std::endl;
  pthread_mutex_unlock(&mutex);
  return NULL;
}

void *func2(void *arg)
{
  pthread_mutex_lock(&mutex);
  int number1, number2, number3;
  std::cout << "Enter number1 \n>>";
  std::cin >> number1;
  std::cout << "Enter number2 \n>>";
  std::cin >> number2;
  std::cout << "Enter number3 \n>>";
  std::cin >> number3;
  pthread_mutex_unlock(&mutex);

  *result = (number1 + number2 + number3);

  std::cout << "The sum is: " << (number1 + number2 + number3) << std::endl;
  return NULL;
}