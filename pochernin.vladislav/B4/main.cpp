#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

#include "data-struct.hpp"

int main()
{
  std::istream_iterator< pochernin::DataStruct > start(std::cin);
  std::istream_iterator< pochernin::DataStruct > finish;
  std::vector < pochernin::DataStruct > vec(start, finish);
  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Incorrect input" << "\n";
    return 2;
  }
  std::sort(vec.begin(), vec.end());
  std::ostream_iterator< pochernin::DataStruct > out(std::cout, "\n");
  std::copy(vec.begin(), vec.end(), out);
}
