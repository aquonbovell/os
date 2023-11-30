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

  pthread_create(&thread1, NULL, computation1, NULL);

  pthread_join(thread1, NULL);

  pthread_create(&thread2, NULL, computation2, NULL);

  pthread_join(thread2, NULL);

  pthread_create(&thread3, NULL, computation3, NULL);

  pthread_join(thread3, NULL);

  pthread_mutex_destroy(&mutex);

  return 0;
}

void *computation1(void *arg)
{
  pthread_mutex_lock(&mutex);
  for (size_t i = 0; i < 20; i++)
  {
    std::cout << (i + 1) << "  ";
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}

void *computation2(void *arg)
{
  pthread_mutex_lock(&mutex);
  for (size_t i = 20; i < 40; i++)
  {
    std::cout << (i + 1) << "  ";
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}

void *computation3(void *arg)
{
  pthread_mutex_lock(&mutex);
  for (size_t i = 40; i < 60; i++)
  {
    std::cout << (i + 1) << "  ";
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}