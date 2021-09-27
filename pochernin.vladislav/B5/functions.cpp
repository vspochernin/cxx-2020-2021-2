#include "functions.hpp"

#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <array>

int pochernin::getTaskNumber(const char* string)
{
  if (std::strlen(string) != 1)
  {
    throw(std::invalid_argument("Incorrect argument (task number)"));
  }
  int argument = std::stoi(string);
  if ((argument != 1) && (argument != 2))
  {
    throw(std::invalid_argument("Incorrect argument (task number)"));
  }
  return argument;
}

unsigned int pochernin::sumVertices(unsigned int sum, const Shape& shape)
{
  return sum + shape.size();
}

bool pochernin::isTriangle(const Shape& shape)
{
  return shape.size() == 3;
}

unsigned int pochernin::getSquaredSide(const Point& lhs, const Point& rhs)
{
  return ((rhs.x - lhs.x) * (rhs.x - lhs.x)) + ((rhs.y - lhs.y) * (rhs.y - lhs.y));
}

void pochernin::fillSquaredSideArray(std::array< unsigned int, 6 >& squaredSides, const Shape& shape)
{
  assert(shape.size() == 4);

  std::transform(shape.begin() + 1, shape.end(), shape.begin(), squaredSides.begin(), getSquaredSide);
  std::transform(shape.begin() + 2, shape.end(), shape.begin(), squaredSides.begin() + 3, getSquaredSide);
  std::transform(shape.begin() + 3, shape.end(), shape.begin(), squaredSides.begin() + 5, getSquaredSide);
}

bool pochernin::isRectangle(const Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }

  sortedPairs pairs = getSortedPairs(shape);

  return std::all_of(pairs.begin(), pairs.end(), pochernin::isTwins);
}

bool pochernin::isSquare(const Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }

  sortedPairs pairs = getSortedPairs(shape);

  return (isRectangle(shape) && (pairs[0] == pairs[1]));
}

bool pochernin::isPentagon(const Shape& shape)
{
  return shape.size() == 5;
}

pochernin::Point pochernin::getFirstPoint(const Shape& shape)
{
  assert(shape.size() > 0);

  return shape[0];
}

void pochernin::deleteExtraSpaces(std::string& str)
{
  std::string::iterator deleteFrom = std::remove(str.begin(), str.end(), ' ');
  str.erase(deleteFrom, str.end());
  deleteFrom = std::remove(str.begin(), str.end(), '\t');
  str.erase(deleteFrom, str.end());
}

void pochernin::sortShapes(std::vector< Shape >& shapes)
{
  std::vector< Shape > temp;

  std::copy_if(shapes.begin(), shapes.end(), std::back_inserter(temp), pochernin::isTriangle);
  std::vector< Shape >::iterator deleteFrom = std::remove_if(shapes.begin(), shapes.end(), pochernin::isTriangle);
  shapes.erase(deleteFrom, shapes.end());

  std::copy_if(shapes.begin(), shapes.end(), std::back_inserter(temp), pochernin::isSquare);
  deleteFrom = std::remove_if(shapes.begin(), shapes.end(), pochernin::isSquare);
  shapes.erase(deleteFrom, shapes.end());

  std::copy_if(shapes.begin(), shapes.end(), std::back_inserter(temp), pochernin::isRectangle);
  deleteFrom = std::remove_if(shapes.begin(), shapes.end(), pochernin::isRectangle);
  shapes.erase(deleteFrom, shapes.end());

  std::copy(shapes.begin(), shapes.end(), std::back_inserter(temp));

  shapes.swap(temp);
}

void pochernin::checkNoLineFeed(const std::string& str)
{
  if (str.find('\n') != str.npos)
  {
    throw(std::invalid_argument("Incorrect point reading"));
  }
}

int pochernin::readCoordinate(const std::string& str)
{
  return std::stoi(str);
}

int pochernin::getWeight(const Shape& shape)
{
  if (isTriangle(shape))
  {
    return 1;
  }
  else if (isSquare(shape))
  {
    return 2;
  }
  else if (isRectangle(shape))
  {
    return 3;
  }
  else
  {
    return 4;
  }
}

pochernin::sortedPairs pochernin::getSortedPairs(const Shape& shape)
{
  assert(shape.size() == 4);

  std::array< unsigned int, 6 > sides;
  fillSquaredSideArray(sides, shape);
  std::sort(sides.begin(), sides.end());

  sortedPairs result = {{{sides[0]}, {sides[1]}}, {{sides[2]}, {sides[3]}}, {{sides[4]}, {sides[5]}}};
  return result;
}

bool pochernin::isTwins(const pochernin::sidesPair& pair)
{
  return pair.first == pair.second;
}
