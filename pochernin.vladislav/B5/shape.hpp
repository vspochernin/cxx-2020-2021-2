#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <iosfwd>

namespace pochernin
{
  struct Point
  {
    int x, y;
  };

  using Shape = std::vector< Point >;

  std::ostream& operator<<(std::ostream& out, const Point& point);
  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);
  std::istream& operator>>(std::istream& in, Shape& shape);
  bool operator<(const Shape& lhs, const Shape& rhs);
}

#endif
