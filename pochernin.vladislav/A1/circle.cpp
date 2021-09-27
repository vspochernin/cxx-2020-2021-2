#include "circle.hpp"

#include <cassert>

const double PI = 3.14159265358979323846;

Circle::Circle(const double radius, const point_t& pos):
  figure_({2.0 * radius, 2.0 * radius, pos})
{
  assert (radius >= 0.0);
}

double Circle::getArea() const
{
  return PI * (figure_.width / 2.0) * (figure_.width / 2.0);
}

rectangle_t Circle::getFrameRect() const
{
  return figure_;
}

void Circle::move(const point_t& destination)
{
  figure_.pos = destination;
}

void Circle::move(const double dx, const double dy)
{
  figure_.pos.x += dx;
  figure_.pos.y += dy;
}
