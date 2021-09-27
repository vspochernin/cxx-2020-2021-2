#ifndef SORT_TEST_TOOLS_HPP
#define SORT_TEST_TOOLS_HPP

#include <cstddef>
#include <vector>
#include <array>

#include "shape.hpp"

namespace pochernin
{
  const size_t defaultVectorSize = 1000;
  const size_t defaultNumberOfTests = 20;

  enum shape_type_t
  {
    triangle = 0,
    square,
    rectangle,
    other
  };

  const std::vector< Shape > differentShapes
  {
    {{0, 0}, {1, 1}, {2, 2}},
    {{1, 2}, {33, 4}, {12, 223}},
    {{50, 40}, {21, 11}, {22, 1232}},

    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 10}, {10, 0}, {10, 10}},
    {{0, 0}, {0, 100}, {100, 0}, {100, 100}},

    {{0, 0}, {0, 2}, {1, 0}, {1, 2}},
    {{0, 0}, {0, 20}, {10, 0}, {10, 20}},
    {{0, 0}, {0, 200}, {100, 0}, {100, 200}},

    {{2320, 210}, {123, 11}, {42, 2232}, {32, 311}},
    {{23, 123}, {1, 1}, {2, 2}, {3, 3}, {32, 434}},
    {{213, 123}, {31, 21}, {22, 2}, {33, 3}, {32, 434}, {123, 1234}}
  };

  using ShapePool = std::array< std::size_t, 4>;

  int getRandomNumber(int min, int max);
  double getRandomRatio();
  ShapePool getShapePool(double ratio);
  Shape getRandomShape(ShapePool& shapePool);
  void fillRandomShapes(std::vector< Shape >& vec, ShapePool shapePool);
}

#endif
