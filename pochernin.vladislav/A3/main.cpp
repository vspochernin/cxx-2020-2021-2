#include <iostream>
#include <cassert>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

using ShapePtr = std::shared_ptr < pochernin::Shape >;

namespace pochernin
{
  void print(const pochernin::Shape& shape, std::ostream& out);
  bool isPosEqual(const pochernin::Shape& shape, const pochernin::point_t& pos);
  void testShape(pochernin::Shape& shape, std::ostream& out, const pochernin::point_t& finishPos);
}

int main()
{
  const double figureWidth = 100.0;
  const double figureHeight = 1000.0;
  const pochernin::point_t startPos = {10.0, 20.0};
  const pochernin::point_t finishPos = {-100.0, 50.0};

  ShapePtr testRectangle = std::make_shared< pochernin::Rectangle >(figureWidth, figureHeight, startPos);
  std::cout << "\nRectangle:\n";
  testShape(*testRectangle, std::cout, finishPos);

  ShapePtr testCircle = std::make_shared< pochernin::Circle >(figureWidth, startPos);
  std::cout << "\nCircle:\n";
  testShape(*testCircle, std::cout, finishPos);

  testRectangle->move(startPos);

  pochernin::CompositeShape compositeShape(testRectangle);
  compositeShape.pushBack(testCircle);
  std::cout << "\nComposite Shape:\n";
  print(compositeShape, std::cout);
}

void pochernin::print(const pochernin::Shape& shape, std::ostream& out)
{
  out << "width: " << pochernin::getWidth(shape) << "\n";
  out << "height: " << pochernin::getHeight(shape) << "\n";
  out << "pos: " << "(" << pochernin::getX(shape)
      << "; " << pochernin::getY(shape) << ")\n";
  out << "area: " << shape.getArea() << "\n\n";
}

bool pochernin::isPosEqual(const pochernin::Shape& shape, const pochernin::point_t& pos)
{
  return ((pochernin::getX(shape) == pos.x) && (pochernin::getY(shape) == pos.y));
}

void pochernin::testShape(pochernin::Shape& shape, std::ostream& out, const pochernin::point_t& finishPos)
{
  print(shape, out);
  shape.move(finishPos);
  assert(isPosEqual(shape, finishPos));
  print(shape, out);
}
