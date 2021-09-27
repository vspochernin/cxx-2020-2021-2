#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <boost/test/unit_test.hpp>

#include "shape.hpp"

namespace pochernin
{
  void boostCheckWidthHeightArea(Shape& shape, rectangle_t startFrameRect, double startArea);
  void checkConstWidthHeightArea(Shape& shape);
  void checkQuadraticChangeAreaWhenScale(Shape& shape);
}

#endif
