#include "shape.hpp"

#include <stdexcept>

#include "base-types.hpp"

void pochernin::Shape::scale(double factor)
{
  if (factor < 0)
  {
    throw(std::invalid_argument("Negative factor"));
  }
  doScale(factor);
}

double pochernin::getX(const Shape& shape)
{
  return shape.getFrameRect().pos.x;
}

double pochernin::getY(const Shape& shape)
{
  return shape.getFrameRect().pos.y;
}

double pochernin::getWidth(const Shape& shape)
{
  return shape.getFrameRect().width;
}

double pochernin::getHeight(const Shape& shape)
{
  return shape.getFrameRect().height;
}
