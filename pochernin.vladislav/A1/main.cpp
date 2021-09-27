#include <iostream>
#include <cassert>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void print(const Shape& shape, std::ostream& out);
bool isPosEqual(const Shape& shape, const point_t& pos);
void testShape(Shape* shape, std::ostream& out, const point_t& finishPos);

int main()
{
  const double figureWidth = 100.0;
  const double figureHeight = 1000.0;
  const point_t startPos = {10.0, 20.0};
  const point_t finishPos = {-100.0, 50.0};

  Shape* testRectangle = new Rectangle(figureWidth, figureHeight, startPos);
  std::cout << "\nRectangle:\n";
  testShape(testRectangle, std::cout, finishPos);

  Shape* testCircle = new Circle(figureWidth, startPos);
  std::cout << "\nCircle:\n";
  testShape(testCircle, std::cout, finishPos);

  delete testRectangle;
  delete testCircle;
}

void print(const Shape& shape, std::ostream& out)
{
  out << "width: " << shape.getFrameRect().width << "\n";
  out << "height: " << shape.getFrameRect().height << "\n";
  out << "pos: " << "(" << shape.getFrameRect().pos.x
      << "; " << shape.getFrameRect().pos.y << ")\n";
  out << "area: " << shape.getArea() << "\n";
}

bool isPosEqual(const Shape& shape, const point_t& pos)
{
  return ((shape.getFrameRect().pos.x == pos.x) && (shape.getFrameRect().pos.y == pos.y));
}

void testShape(Shape* shape, std::ostream& out, const point_t& finishPos)
{
  print(*shape, out);
  shape->move(finishPos);
  assert(isPosEqual(*shape, finishPos));
  print(*shape, out);
}
