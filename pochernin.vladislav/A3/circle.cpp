#include "circle.hpp"

#include <cassert>
#include <stdexcept>

namespace pochernin
{
  const double PI = 3.14159265358979323846;
}

pochernin::Circle::Circle(const double radius, const pochernin::point_t& pos):
  figure_({2.0 * radius, 2.0 * radius, pos})
{
  if (radius < 0)
  {
    throw(std::invalid_argument("Negative radius"));
  }
}

double pochernin::Circle::getArea() const
{
  return pochernin::PI * (figure_.width / 2.0) * (figure_.width / 2.0);
}

pochernin::rectangle_t pochernin::Circle::getFrameRect() const
{
  return figure_;
}

void pochernin::Circle::move(const pochernin::point_t& destination)
{
  figure_.pos = destination;
}

void pochernin::Circle::move(const double dx, const double dy)
{
  figure_.pos.x += dx;
  figure_.pos.y += dy;
}

void pochernin::Circle::doScale(const double factor)
{
  figure_.width *= factor;
  figure_.height *= factor;
}
