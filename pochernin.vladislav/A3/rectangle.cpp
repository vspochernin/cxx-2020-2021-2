#include "rectangle.hpp"

#include <cassert>
#include <stdexcept>

pochernin::Rectangle::Rectangle(const double width, const double height, const pochernin::point_t& pos):
  figure_({width, height, pos})
{
  if (width < 0)
  {
    throw(std::invalid_argument("Negative width"));
  }
  if (height < 0)
  {
    throw(std::invalid_argument("Negative height"));
  }
}

double pochernin::Rectangle::getArea() const
{
  return figure_.width * figure_.height;
}

pochernin::rectangle_t pochernin::Rectangle::getFrameRect() const
{
  return figure_;
}

void pochernin::Rectangle::move(const pochernin::point_t& destination)
{
  figure_.pos = destination;
}

void pochernin::Rectangle::move(const double dx, const double dy)
{
  figure_.pos.x += dx;
  figure_.pos.y += dy;
}

void pochernin::Rectangle::doScale(const double factor)
{
  figure_.width *= factor;
  figure_.height *= factor;
}
