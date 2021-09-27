#include "test-functions.hpp"

#include "base-types.hpp"

namespace pochernin
{
  const double accuracy = 0.0001;
  const double dx = 10.0;
  const double dy = 20.0;
  const point_t finishPos = {100.0, 200.0};
  const double factor = 4;
}

void pochernin::boostCheckWidthHeightArea(Shape& shape, rectangle_t startFrameRect, double startArea)
{
  BOOST_CHECK_CLOSE(startFrameRect.width, getWidth(shape), pochernin::accuracy);
  BOOST_CHECK_CLOSE(startFrameRect.height, getHeight(shape), pochernin::accuracy);
  BOOST_CHECK_CLOSE(startArea, shape.getArea(), pochernin::accuracy);
}

void pochernin::checkConstWidthHeightArea(Shape& shape)
{
  pochernin::rectangle_t startFrameRect = shape.getFrameRect();
  double startArea = shape.getArea();
  shape.move(pochernin::dx, pochernin::dy);
  boostCheckWidthHeightArea(shape, startFrameRect, startArea);
  shape.move(pochernin::finishPos);
  boostCheckWidthHeightArea(shape, startFrameRect, startArea);
}

void pochernin::checkQuadraticChangeAreaWhenScale(Shape& shape)
{
  double startArea = shape.getArea();
  shape.scale(pochernin::factor);
  BOOST_CHECK_CLOSE(startArea * pochernin::factor * pochernin::factor, shape.getArea(), pochernin::accuracy);
}
