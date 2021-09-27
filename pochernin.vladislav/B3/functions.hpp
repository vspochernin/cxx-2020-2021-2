#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iosfwd>

namespace pochernin
{
  using ValueType = unsigned int;

  const ValueType maxNumber = 11;
  const ValueType minNumber = 1;

  int getTaskNumber(const char* string);
  ValueType getFactorial(ValueType number);

  void invalidCommand(std::ostream& out);
  void invalidBookmark(std::ostream& out);
  void invalidStep(std::ostream& out);
  void empty(std::ostream& out);
}

#endif
