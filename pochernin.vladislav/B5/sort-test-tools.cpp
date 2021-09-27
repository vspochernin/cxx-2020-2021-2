#include "sort-test-tools.hpp"

#include <cstdlib>
#include <cassert>
#include <algorithm>

int pochernin::getRandomNumber(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

double pochernin::getRandomRatio()
{
  return rand() / static_cast< double >(RAND_MAX);
}

pochernin::ShapePool pochernin::getShapePool(double ratio)
{
  assert((ratio >= 0) && (ratio <= 1));
  ShapePool shapePool;

  size_t remaining = defaultVectorSize;

  size_t add = remaining * ratio;
  shapePool[shape_type_t::other] = add;
  remaining -= add;

  ratio = getRandomRatio();
  add = remaining * ratio;
  shapePool[shape_type_t::triangle] = add;
  remaining -= add;

  ratio = getRandomRatio();
  add = remaining * ratio;
  shapePool[shape_type_t::square] = add;
  remaining -= add;

  shapePool[shape_type_t::rectangle] = remaining;

  return shapePool;
}

pochernin::Shape pochernin::getRandomShape(ShapePool& shapePool)
{
  Shape result;

  size_t typeShape = 0;
  do
  {
    typeShape = getRandomNumber(0, 3);
  } while (shapePool[typeShape] == 0);

  size_t type = getRandomNumber(0, 2);
  if (typeShape == shape_type_t::triangle)
  {
    result = differentShapes[type];
    shapePool[typeShape]--;
  }
  else if (typeShape == shape_type_t::square)
  {
    result = differentShapes[3 + type];
    shapePool[typeShape]--;
  }
  else if (typeShape == shape_type_t::rectangle)
  {
    result = differentShapes[6 + type];
    shapePool[typeShape]--;
  }
  else if (typeShape == shape_type_t::other)
  {
    result = differentShapes[9 + type];
    shapePool[typeShape]--;
  }

  return result;
}

void pochernin::fillRandomShapes(std::vector< Shape >& vec, ShapePool shapePool)
{
  std::fill(vec.begin(), vec.end(), getRandomShape(shapePool));
}
