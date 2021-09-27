#include "functions.hpp"

#include <cstring>
#include <cctype>
#include <cstdlib>
#include <stdexcept>
#include <iostream>

int pochernin::getTaskNumber(const char* string)
{
  if (strlen(string) != 1)
  {
    return -1;
  }
  if (!std::isdigit(string[0]))
  {
    return -1;
  }
  int argument = std::atoi(string);
  if ((argument != 1) && (argument != 2))
  {
    return -1;
  }
  return argument;
}

pochernin::ValueType pochernin::getFactorial(ValueType number)
{
  if (number > maxNumber)
  {
    throw(std::invalid_argument("Too big number to get factorial"));
  }
  else
  {
    return ((number <= 1) ? 1 : (number * getFactorial(number - 1)));
  }
}

void pochernin::invalidCommand(std::ostream& out)
{
  out << "<INVALID COMMAND>\n";
}

void pochernin::invalidBookmark(std::ostream& out)
{
  out << "<INVALID BOOKMARK>\n";
}

void pochernin::invalidStep(std::ostream& out)
{
  out << "<INVALID STEP>\n";
}

void pochernin::empty(std::ostream& out)
{
  out << "<EMPTY>\n";
}
