#include "tasks.hpp"

#include <iostream>
#include <iterator>
#include <set>

void pochernin::task1(std::istream& in, std::ostream& out)
{
  std::istream_iterator< std::string > startIterator(in);
  std::istream_iterator< std::string > finishIterator;
  std::set< std::string > words(startIterator, finishIterator);

  std::ostream_iterator< std::string > outIterator(out, "\n");
  std::copy(words.begin(), words.end(), outIterator);
}
