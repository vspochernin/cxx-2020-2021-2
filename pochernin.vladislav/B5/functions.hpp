#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>
#include <vector>
#include <array>

#include "shape.hpp"

namespace pochernin
{
  using sidesPair = std::pair< unsigned int, unsigned int >;
  using sortedPairs = std::vector< sidesPair >;

  int getTaskNumber(const char* string);
  unsigned int sumVertices(unsigned int sum, const Shape& shape);
  bool isTriangle(const Shape& shape);
  void fillSquaredSideArray(std::array< unsigned int, 6 >& squaredSides, const Shape& shape);
  unsigned int getSquaredSide(const Point& lhs, const Point& rhs);
  bool isRectangle(const Shape& shape);
  bool isSquare(const Shape& shape);
  bool isPentagon(const Shape& shape);
  Point getFirstPoint(const Shape& shape);
  void deleteExtraSpaces(std::string& str);
  void sortShapes(std::vector< Shape >& shapes);
  void checkNoLineFeed(const std::string& str);
  int readCoordinate(const std::string& str);
  int getWeight(const Shape& shape);
  sortedPairs getSortedPairs(const Shape& shape);
  bool isTwins(const sidesPair& pair);
}

#endif
