#include <iostream>
#include <stdexcept>

#include "functions.hpp"
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      throw(std::invalid_argument("Incorrect count of arguments"));
    }

    int taskNumber = pochernin::getTaskNumber(argv[1]);
    if (taskNumber == 1)
    {
      pochernin::task1(std::cin, std::cout);
    }
    else if (taskNumber == 2)
    {
      pochernin::task2(std::cout);
    }
    else
    {
      throw(std::invalid_argument("Incorrect argument (task number)"));
    }
  }
  catch (std::invalid_argument& error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
  catch (std::runtime_error& error)
  {
    std::cerr << error.what() << "\n";
    return 2;
  }

  return 0;
}
