#include "tasks.hpp"

#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "functions.hpp"

void pochernin::task2(const char* fileName)
{
  if (!fileName)
  {
    throw (std::invalid_argument("Incorrect file name"));
  }
  std::ifstream file(fileName);
  if (!file)
  {
    throw (std::runtime_error("File open error"));
  }

  size_t capacity = 1;
  size_t size = 0;
  std::unique_ptr< char[] > data = std::make_unique< char[] >(capacity);

  while (file)
  {
    file.read(data.get() + size, capacity - size);
    size += file.gcount();
    if (size == capacity)
    {
      capacity *= 2;
      std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
      std::move(data.get(), data.get() + size, temp.get());
      data = std::move(temp);
    }
  }

  file.close();
  std::vector< char > vec(data.get(), data.get() + size);
  for (size_t i = 0; i < size; i++)
  {
    std::cout << vec[i];
  }
}
