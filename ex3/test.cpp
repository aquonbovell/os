// Name : Aquon Bovell, ID : 417002714, Date : 09 / 26 / 2023

#include "iostream"
#include "set"
#include <algorithm>
#define BUF_SIZE 10

using namespace std;

typedef struct
{
  int price;
  char type;
} item;

item buffer[BUF_SIZE];
int in = 0;
int out = 0;
int counter = 0;

void Consumer_Remove()
{
  int iterations = 0;
  while (iterations < 4)
  {
    while (counter == 0)
    {
      std::cout << "Buffer is empty\n";
    }

    // remove an item from the buffer
    item nextConsumed = buffer[out];
    out = (out + 1) % BUF_SIZE;
    counter--;
    iterations++;
  }
  for (size_t i = 0; i < BUF_SIZE; i++)
  {
    std::cout << buffer[i].price << ", " << buffer[i].type << "\n";
  }
}

item nextProduced()
{
  char type[4] = {'A', 'B', 'C', 'D'};

  item newItem = item();
  newItem.price = rand() % 50 + 1;

  newItem.type = type[rand() % size(type)];
  return newItem;
}

void Producer_Insert()
{
  int iterations = 0;
  while (iterations < 6)
  {
    while (counter == BUF_SIZE)
    {
      std::cout << "Buffer Full\n";
    }

    // remove an item from the buffer
    buffer[in] = nextProduced();
    in = (in + 1) % BUF_SIZE;
    counter--;
    iterations++;
  }

  for (size_t i = 0; i < BUF_SIZE; i++)
  {
    std::cout << buffer[i].price << ", " << buffer[i].type << "\n";
  }
}

int main()
{
  Producer_Insert();
  Consumer_Remove();
}