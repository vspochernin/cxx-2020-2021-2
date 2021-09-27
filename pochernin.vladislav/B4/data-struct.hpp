#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <string>
#include <iosfwd>

namespace pochernin
{
  struct DataStruct
  {
    int key1 = 0;
    int key2 = 0;
    std::string str;
  };
  bool operator<(const DataStruct& lhs, const DataStruct& rhs);
  std::istream& operator>>(std::istream& in, DataStruct& dataStruct);
  std::ostream& operator<<(std::ostream& out, const DataStruct& dataStruct);
  int getKey(std::istream& in);
}

#endif
