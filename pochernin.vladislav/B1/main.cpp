#include <stdexcept>
#include <iostream>

#include "tasks.hpp"
#include "functions.hpp"

int main(int argc, char* argv[])
{
  srand(time(0));

  try
  {
    if ((argc < 2) || (argc > 4))
    {
      throw(std::invalid_argument("Incorrect count of arguments"));
    }
    if (!pochernin::isNumber(argv[1]))
    {
      throw(std::invalid_argument("Incorrect first argument (task number)"));
    }
    switch (atoi(argv[1]))
    {
    case 1:
      if (argc != 3)
      {
        throw(std::invalid_argument("Incorrect count of arguments for task 1"));
      }
      pochernin::task1(argv[2]);
      break;
    case 2:
      if (argc != 3)
      {
        throw(std::invalid_argument("Incorrect count of arguments for task 2"));
      }
      pochernin::task2(argv[2]);
      break;
    case 3:
      if (argc != 2)
      {
        throw(std::invalid_argument("Incorrect count of arguments for task 3"));
      }
      pochernin::task3();
      break;
    case 4:
      if (argc != 4)
      {
        throw(std::invalid_argument("Incorrect count of arguments for task 4"));
      }
      if (!pochernin::isNumber(argv[3]))
      {
        throw(std::invalid_argument("Incorrect third argument (vector size in task 4)"));
      }
      if (atoi(argv[3]) <= 0)
      {
        throw(std::invalid_argument("Incorrect array size"));
      }
      pochernin::task4(argv[2], atoi(argv[3]));
      break;
    default:
      throw(std::invalid_argument("Incorrect task number"));
      break;
    }
  }
  catch (std::exception& error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }

  return 0;
}
