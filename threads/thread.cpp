#include "iostream"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

void *computation1(void *arg);
void *computation2(void *arg);
void *computation3(void *arg);

int main()
{
  pthread_t thread1;
  pthread_t thread2;
  pthread_t thread3;

  pthread_mutex_init(&mutex, NULL);

  int *result1 = new int;

  pthread_create(&thread1, NULL, computation1, (void *)result1);

  pthread_create(&thread2, NULL, computation2, (void *)result1);

  pthread_create(&thread3, NULL, computation3, (void *)result1);

  pthread_join(thread1, NULL);

  pthread_join(thread2, NULL);

  pthread_join(thread3, NULL);

  return 0;
}

void *computation1(void *arg)
{
  pthread_mutex_lock(&mutex);
  int *result = (int *)arg;
  *result = 0;
  int sum;
  for (size_t i = 1; i < 101; i++)
  {
    sum += i;
  }
  std::cout << "R1: " << sum << "\n";
  *result = sum;
  pthread_mutex_unlock(&mutex);
  return NULL;
}

void *computation2(void *arg)
{
  pthread_mutex_lock(&mutex);
  int *result = (int *)arg;
  int sum;
  for (size_t i = 101; i < 201; i++)
  {
    sum += i;
  }
  std::cout << "R2: " << *result +sum << "\n";
  *result += sum;
  pthread_mutex_unlock(&mutex);
  return NULL;
}

void *computation3(void *arg)
{
  pthread_mutex_lock(&mutex);
  int *result = (int *)arg;
  int sum;
  for (size_t i = 201; i < 301; i++)
  {
    sum += i;
  }
  std::cout << "R3: " <<*result +sum << "\n";
  *result += sum;
  pthread_mutex_unlock(&mutex);
  return NULL;
}