#include "tasks.hpp"

#include <iostream>
#include <algorithm>

#include "factorial-container.hpp"

void pochernin::task2(std::ostream& out)
{
  std::ostream_iterator< FactorialContainer::ValueType > output(out, " ");
  FactorialContainer fc;
  std::copy(fc.begin(), fc.end(), output);
  out << "\n";
  std::reverse_copy(fc.begin(), fc.end(), output);
  out << "\n";
}
