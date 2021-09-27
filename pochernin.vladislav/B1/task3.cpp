#include "tasks.hpp"

#include <iostream>
#include <vector>

#include "functions.hpp"

void pochernin::task3()
{
  std::vector< int > vec;
  int n = 0;
  while(std::cin >> n)
  {
    if (n == 0)
    {
      break;
    }
    vec.push_back(n);
  }
  if ((n != 0) || (!std::cin.eof() && std::cin.fail()) || std::cin.bad())
  {
    throw(std::runtime_error("Incorrect input in task3\n"));
  }

  if (vec.empty())
  {
    return;
  }

  std::vector< int >::iterator i = vec.begin();
  if (vec.back() == 1)
  {
    while (i != vec.end())
    {
      if ((*i % 2) == 0)
      {
        i = vec.erase(i);
      }
      else
      {
        i++;
      }
    }
  }
  else if (vec.back() == 2)
  {
    while (i != vec.end())
    {
      if ((*i % 3) == 0)
      {
        i = vec.insert(i + 1, 3, 1);
        i += 2;
      }
      else
      {
        i++;
      }
    }
  }

  pochernin::print(vec, " ");
}
