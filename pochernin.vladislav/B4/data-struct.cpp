#include "data-struct.hpp"

#include <iostream>
#include <string>
#include <sstream>

bool pochernin::operator<(const DataStruct& lhs, const DataStruct& rhs)
{
  if (lhs.key1 != rhs.key1)
  {
    return lhs.key1 < rhs.key1;
  }
  else if (lhs.key2 != rhs.key2)
  {
    return lhs.key2 < rhs.key2;
  }
  else
  {
    return lhs.str.length() < rhs.str.length();
  }
}

std::ostream& pochernin::operator<<(std::ostream& out, const DataStruct& dataStruct)
{
  out << dataStruct.key1 << ", " << dataStruct.key2 << ", " << dataStruct.str;
  return out;
}

std::istream& pochernin::operator>>(std::istream& in, DataStruct& dataStruct)
{
  std::string str;
  std::getline(in, str);
  std::stringstream stream(str);

  dataStruct.key1 = getKey(stream);
  if (stream.fail())
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  dataStruct.key2 = getKey(stream);
  if (stream.fail())
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  std::getline(stream, str);
  if (stream.fail())
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  dataStruct.str = str;
  return in;
}

int pochernin::getKey(std::istream& in)
{
  std::string str;
  std::getline(in, str, ',');
  int key = 0;
  try
  {
    key = std::stoi(str);
  }
  catch (std::exception& error)
  {
    in.setstate(std::ios::failbit);
    return 0;
  }
  if (std::abs(key) > 5)
  {
    in.setstate(std::ios::failbit);
    return 0;
  }
  return key;
}
