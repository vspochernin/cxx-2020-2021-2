#include "rectangle.hpp"

#include <cassert>

Rectangle::Rectangle(const double width, const double height, const point_t& pos):
  figure_({width, height, pos})
{
  assert (width >= 0.0);
  assert (height >= 0.0);
}

double Rectangle::getArea() const
{
  return figure_.width * figure_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return figure_;
}

void Rectangle::move(const point_t& destination)
{
  figure_.pos = destination;
}

void Rectangle::move(const double dx, const double dy)
{
  figure_.pos.x += dx;
  figure_.pos.y += dy;
}
